#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Constants.h"

void ResizeWindow(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(aspectRatio * Constants::VIEW_HEIGHT, Constants::VIEW_HEIGHT);
}


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DAVE");
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/dave1.png");
    sf::RectangleShape referenceBlock(Constants::UNIT_SIZE);
    referenceBlock.setFillColor(sf::Color::Blue);
    referenceBlock.setPosition(Constants::UNIT_SIZE * 5.0f);
    Player player(&playerTexture, Constants::UNIT_SIZE, sf::Vector2f(1.5 * Constants::UNIT_SIZE.x, 9 * Constants::UNIT_SIZE.y), 2 * Constants::UNIT_SIZE.x);

    sf::Clock clock;
    float deltaTime;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                ResizeWindow(window, view);
                break;
            }
        }
        deltaTime = clock.restart().asSeconds();

        player.Update(deltaTime);

        window.clear();
        window.setView(view);
        view.setCenter(player.getPosition());
        player.Draw(window);
        window.draw(referenceBlock);
        window.display();
    }
    std::cout << "Exit status 0" << std::endl;
    return 0;
}
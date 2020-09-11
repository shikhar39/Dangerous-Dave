#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Constants.h"

void ResizeWindow(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(aspectRatio * Constants::VIEW_HEIGHT, Constants::VIEW_HEIGHT);
}


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DAVE");
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/dave202.png");
    sf::Vector2u textureCount(2, 3);
    Player player(&playerTexture, textureCount, 0.3f, Constants::UNIT_SIZE, sf::Vector2f(1.5 * Constants::UNIT_SIZE.x, 9 * Constants::UNIT_SIZE.y), 2 * Constants::UNIT_SIZE.x);
    view.setCenter(player.getPosition());

    sf::Texture platformTexture;
    platformTexture.loadFromFile("assets/redTile.png");
    Platform referencePlatform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(0 * Constants::UNIT_SIZE.x, 9 * Constants::UNIT_SIZE.y));
    Platform referencePlatform2(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(1.5 * Constants::UNIT_SIZE.x, 11 * Constants::UNIT_SIZE.y));


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
        if (referencePlatform.checkCollision(player, player.getDirection(), 0.2f)) {
            player.onCollision();
        }
        if (referencePlatform2.checkCollision(player, player.getDirection(), 0.2f)) {
            player.onCollision();
        }


        window.clear();
        window.setView(view);
        //view.setCenter(player.getPosition());
        player.Draw(window);
        referencePlatform.Draw(window);
        referencePlatform2.Draw(window);
        window.display();
    }
    std::cout << "Exit status 0" << std::endl;
    return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Constants.h"
#include "Collectable.h"
#include <thread>
#include <chrono>

void ResizeWindow(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(aspectRatio * Constants::VIEW_HEIGHT, Constants::VIEW_HEIGHT);
}


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DAVE");
    window.setFramerateLimit(144);
    //window.setVerticalSyncEnabled(true):
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(3.3 * Constants::VIEW_HEIGHT, Constants::VIEW_HEIGHT));


    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/dave202.png");
    sf::Texture platformTexture;
    platformTexture.loadFromFile("assets/redTile.png");
    sf::Texture doorTexture;
    doorTexture.loadFromFile("assets/door.png");
    sf::Texture diamondsTexture;
    diamondsTexture.loadFromFile("assets/diamonds.png");
    sf::Texture redDiamondsTexture;
    redDiamondsTexture.loadFromFile("assets/redDiamonds.png");
    sf::Texture sphereTexture;
    sphereTexture.loadFromFile("assets/sphere.png");
    sf::Texture trophyTexture;
    trophyTexture.loadFromFile("assets/cup1.png");



    sf::Vector2u textureCount(2, 3);
    Player player(&playerTexture, textureCount, 0.3f, Constants::UNIT_SIZE, sf::Vector2f(2.5 * Constants::UNIT_SIZE.x, 8 * Constants::UNIT_SIZE.y), 3 * Constants::UNIT_SIZE.x);
    view.setCenter(9 * Constants::UNIT_SIZE.x, 4.5 * Constants::UNIT_SIZE.y);



    std::vector<Platform> platforms;
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(Constants::UNIT_SIZE.x ,9 * Constants::UNIT_SIZE.y), sf::Vector2f(0.5 * Constants::UNIT_SIZE.x, 4.5 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(Constants::UNIT_SIZE.x ,9 * Constants::UNIT_SIZE.y), sf::Vector2f(18.5 * Constants::UNIT_SIZE.x, 4.5 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(19 * Constants::UNIT_SIZE.x , Constants::UNIT_SIZE.y), sf::Vector2f(9.5 * Constants::UNIT_SIZE.x, 0 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, sf::Vector2f(19 * Constants::UNIT_SIZE.x , Constants::UNIT_SIZE.y), sf::Vector2f(9.5 * Constants::UNIT_SIZE.x, 9 * Constants::UNIT_SIZE.y)));
    //Entrance
    platforms.push_back(Platform(&doorTexture, Constants::UNIT_SIZE, sf::Vector2f(1.5 * Constants::UNIT_SIZE.x, 8 * Constants::UNIT_SIZE.y)));
    // Adding inner blocks 
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(1.5 * Constants::UNIT_SIZE.x, 5 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(3.5 * Constants::UNIT_SIZE.x, 3 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(5.5 * Constants::UNIT_SIZE.x, 5 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(7.5 * Constants::UNIT_SIZE.x, 3 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(9.5 * Constants::UNIT_SIZE.x, 5 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(11.5 * Constants::UNIT_SIZE.x, 3 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(13.5 * Constants::UNIT_SIZE.x, 5 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(15.5 * Constants::UNIT_SIZE.x, 3 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(17.5 * Constants::UNIT_SIZE.x, 5 * Constants::UNIT_SIZE.y)));
        
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(4.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(5.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(6.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(7.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(11.5 * Constants::UNIT_SIZE.x, 8 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(11.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(12.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(13.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(14.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(15.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));
    platforms.push_back(Platform(&platformTexture, Constants::UNIT_SIZE, sf::Vector2f(16.5 * Constants::UNIT_SIZE.x, 7 * Constants::UNIT_SIZE.y)));

    std::vector<Collectable> collectables;
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(1.5 * Constants::UNIT_SIZE.x, 4 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(1.5 * Constants::UNIT_SIZE.x, 6 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(3.5 * Constants::UNIT_SIZE.x, 2 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(5.5 * Constants::UNIT_SIZE.x, 4 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(7.5 * Constants::UNIT_SIZE.x, 2 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(7.5 * Constants::UNIT_SIZE.x, 6 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(9.5 * Constants::UNIT_SIZE.x, 4 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(13.5 * Constants::UNIT_SIZE.x, 4 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(15.5 * Constants::UNIT_SIZE.x, 2 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&diamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(17.5 * Constants::UNIT_SIZE.x, 4 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&redDiamondsTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(17.5 * Constants::UNIT_SIZE.x, 1 * Constants::UNIT_SIZE.y)));
    collectables.push_back(Collectable(&sphereTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(1.5 * Constants::UNIT_SIZE.x, 1 * Constants::UNIT_SIZE.y)));


    std::vector<sf::RectangleShape> victory;
    for (int i = 0; i < 3; i++) {
        sf::RectangleShape victoryTrophy;
        victoryTrophy.setSize(Constants::UNIT_SIZE);
        victoryTrophy.setOrigin(Constants::UNIT_SIZE / 2.0f);
        victoryTrophy.setTexture(&trophyTexture);
        victoryTrophy.setPosition(( 7.5 + i ) * Constants::UNIT_SIZE.x , 10 * Constants::UNIT_SIZE.y);
        victory.push_back(victoryTrophy);
    }

    Collectable trophy(&trophyTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(11.5 * Constants::UNIT_SIZE.x, 2 * Constants::UNIT_SIZE.y));
    Collectable exit(&doorTexture, 0.8f * Constants::UNIT_SIZE, sf::Vector2f(12.5 * Constants::UNIT_SIZE.x, 8 * Constants::UNIT_SIZE.y));

    sf::Clock clock;
    float deltaTime;
    bool trophyCollected = false;
    bool levelFinished = false;

    while (window.isOpen() && !levelFinished) {
        window.clear();
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
        
        for (Platform& platform : platforms) {
            if (platform.checkCollision(player, player.getDirection(), 1.0f))
                player.onCollision();
        }
        for (auto it = collectables.begin(); it != collectables.end();) {
            Collectable& collectable = *it;
            if (it->checkCollision(player, player.getDirection(), 1.0f)) {
                it = collectables.erase(it);
            }
            else
                it++;
        }
        if (!trophyCollected) {
            trophy.Draw(window);
            if (trophy.checkCollision(player, player.getDirection(), 1.0f)) {
                trophy.~Collectable();
                trophyCollected = true;
            }
        }
        else {
            if (exit.checkCollision(player, player.getDirection(), 1.0f)) {
                std::cout << "Finished" << std::endl;
                for (sf::RectangleShape& vic : victory) {
                    window.draw(vic);
                    levelFinished = true;
                }

            }
        }
        window.setView(view);
        //view.setCenter(player.getPosition());
        player.Draw(window);
        for (Platform& platform : platforms) {
            platform.Draw(window);
        }
        for (Collectable& collectable : collectables) {
            collectable.Draw(window);
        }
        exit.Draw(window);
        window.display();
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Exit status 0" << std::endl;
    return 0;
}
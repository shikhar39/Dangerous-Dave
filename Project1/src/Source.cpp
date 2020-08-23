#include <SFML/Graphics.hpp>
#include "Player.h"

const sf::Vector2f UNIT_SIZE(100.0f, 100.0f);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DAVE");
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/dave1.png");
    
    Player player(&playerTexture, UNIT_SIZE, sf::Vector2f(1.5 * UNIT_SIZE.x, 9 * UNIT_SIZE.y), 3 * UNIT_SIZE.x);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.setView(view);
        view.setCenter(player.getPosition());
        player.Draw(window);
        window.display();
    }

    return 0;
}
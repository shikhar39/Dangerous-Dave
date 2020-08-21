#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(sf::Vector2f size, sf::Vector2f position);
	~Player();
private:
	sf::RectangleShape body;
	sf::Vector2f velocity;
	bool facingRight;
};
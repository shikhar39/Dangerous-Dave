#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed);
	~Player();

	void Update();

private:
	sf::RectangleShape body;
	sf::Vector2f velocity;
	bool facingRight;
	float speed;
};
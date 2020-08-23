#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
	sf::Vector2f getPosition() { return body.getPosition(); }

private:
	sf::RectangleShape body;
	sf::Vector2f velocity;
	bool facingRight;
	float speed;
	float jumpHeight;
	bool canJump;
};
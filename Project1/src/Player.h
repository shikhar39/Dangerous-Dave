#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collidable.h"
class Player : public Collidable {
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
	sf::Vector2f getPosition() { return body.getPosition(); }

private:
	Animation playerAnimation;
	sf::Vector2f velocity;
	bool facingRight;
	float speed;
	float jumpHeight;
	bool canJump;
};
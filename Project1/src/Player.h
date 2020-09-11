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
	void onCollision();
	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f* getDirection() { return &direction; }

private:
	Animation playerAnimation;
	sf::Vector2f velocity;
	sf::Vector2f direction;
	bool facingRight;
	float speed;
	float jumpHeight;
	bool canJump;
};
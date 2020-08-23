#include "Player.h"
#include "Constants.h"

Player::Player(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed){
	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	facingRight = true;
	this->speed = speed;
	canJump = true;
	jumpHeight = size.y * 3;
}

Player::~Player()
{
}

void Player::Update(float deltaTime){
	velocity.x = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		velocity.x += speed;
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		canJump = false;
		velocity.y = -sqrtf(2.0f * Constants::GRAVITY * jumpHeight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		canJump = false;
		velocity.y = -sqrtf(2.0f * Constants::GRAVITY * jumpHeight);
	}*/
	body.move(velocity.x * deltaTime, 0.0f);
}

void Player::Draw(sf::RenderWindow& window){
	window.draw(body);
	//window.s
}

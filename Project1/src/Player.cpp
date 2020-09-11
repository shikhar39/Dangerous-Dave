#include "Player.h"
#include "Constants.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position, float speed):
	playerAnimation(texture, imageCount, switchTime)
{
	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	facingRight = true;
	this->speed = speed;
	canJump = true;
	jumpHeight = size.y * 2;
	velocity.y = 0.0f;
}

Player::~Player()
{
}

void Player::Update(float deltaTime){
	velocity.x = 0.0f;
	velocity.y += Constants::GRAVITY * deltaTime;
	int row;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		velocity.x += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canJump) {
		canJump = false;
		velocity.y = -sqrtf(2.0f * Constants::GRAVITY * jumpHeight);
	}
	if (velocity.x == 0.0f) {
		row = 0;
	}
	else {
		row = 1;
		if (velocity.x > 0.0f) {
			facingRight = true;
		}
		else {
			facingRight = false;
		}
	}
	body.move(velocity.x * deltaTime, velocity.y * deltaTime);
	if (!canJump)
		row = 2;
	playerAnimation.Update(row, facingRight, deltaTime);
	body.setTextureRect(playerAnimation.uvRect);
}

void Player::onCollision(){
	if (direction.x != 0)
		velocity.x = 0;
	if (direction.y < 0.0f) {
		//Collision on the bottom
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		//Collision on the top
		velocity.y = 0.0f;
	}
}


void Player::Draw(sf::RenderWindow& window){
	window.draw(body);
	//window.s
}


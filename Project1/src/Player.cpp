#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed){
	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	facingRight = true;
	this->speed = speed;
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw(sf::RenderWindow& window){
	window.draw(body);
	//window.s
}

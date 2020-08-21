#include "Player.h"


Player::Player(sf::Vector2f size, sf::Vector2f position){
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	facingRight = true;
}

Player::~Player()
{
}

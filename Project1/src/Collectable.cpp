#include "Collectable.h"

Collectable::Collectable(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position){
	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
}

Collectable::~Collectable(){
}

void Collectable::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

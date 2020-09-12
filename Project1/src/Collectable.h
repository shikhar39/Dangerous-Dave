#pragma once
#include <SFML/Graphics.hpp>
#include "Collidable.h"

class Collectable : public Collidable {
public:
	Collectable(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Collectable();
	void Draw(sf::RenderWindow& window);
};
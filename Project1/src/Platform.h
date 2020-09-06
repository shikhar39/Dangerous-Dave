#pragma once

#include "Collidable.h"
#include <SFML/Graphics.hpp>

class Platform : public Collidable {
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();
	void Draw(sf::RenderWindow &window);
private:
	sf::Texture texture;
};
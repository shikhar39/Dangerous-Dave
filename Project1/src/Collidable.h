#pragma once
#include <SFML/Graphics.hpp>

class Collidable {
public:
	Collidable();
	~Collidable();
	
	bool checkCollision(Collidable other);

	sf::RectangleShape body;
protected:

};
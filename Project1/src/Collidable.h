#pragma once
#include <SFML/Graphics.hpp>

class Collidable {
public:
	Collidable();
	~Collidable();
	
	bool checkCollision(Collidable &other, sf::Vector2f* direction, float mass);
	void Move(float x, float y);
	sf::RectangleShape body;
protected:
	

};
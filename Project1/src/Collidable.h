#pragma once
#include <SFML/Graphics.hpp>

class Collidable {
public:
	Collidable();
	~Collidable();
	
	bool checkCollision(Collidable &other, float mass);
	void Move(float x, float y);
	sf::RectangleShape body;
protected:
	

};
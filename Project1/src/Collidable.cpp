#include "Collidable.h"
Collidable::Collidable()
{
}

Collidable::~Collidable()
{
}

bool Collidable::checkCollision(Collidable &other, sf::Vector2f* direction, float mass)
{
	float distanceX = body.getPosition().x - other.body.getPosition().x;
	float distanceY = body.getPosition().y - other.body.getPosition().y;
	float separationX = abs(distanceX) - (body.getSize().x + other.body.getSize().x) / 2.0f;
	float separationY = abs(distanceY) - (body.getSize().y + other.body.getSize().y) / 2.0f;
	
	if (separationX <= 0.0f && separationY <= 0.0f) {
		mass = std::min(std::max(mass, 0.0f), 1.0f);
		if (separationX > separationY) {
			if (distanceX > 0.0f) {
				//Other Object (generally player) on the left
				Move(-separationX * (1.0f - mass), 0.0f);
				other.Move(separationX * mass, 0.0f);

				direction->x = -1.0f;
				direction->y = 0.0f;
			}
			else {
				//Other Object (generally player) on the right
				Move(separationX * (1.0f - mass), 0.0f);
				other.Move(-separationX * mass, 0.0f);

				direction->x = 1.0f;
				direction->y = 0.0f;
			}
		}
		else {
			if (distanceY > 0.0f) {
				//Other Object (generally player) on top 
				Move(0.0f, -separationY * (1.0f - mass));
				other.Move(0.0f, separationY * mass);

				direction->x = 0.0f;
				direction->y = -1.0f;
			}
			else {
				//Other Object (generally player) below this object 
				Move(0.0f, separationY * (1.0f - mass));
				other.Move(0.0f, -separationY * mass);

				direction->x = 0.0f;
				direction->y = 1.0f;
			}
		}
		return true;
	}
	return false;
}

void Collidable::Move(float x, float y)
{
	body.move(x, y);
}

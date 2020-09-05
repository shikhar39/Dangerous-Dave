#include "Collidable.h"

Collidable::Collidable()
{
}

Collidable::~Collidable()
{
}

bool Collidable::checkCollision(Collidable other)
{
	float distanceX = abs(body.getPosition().x - other.body.getPosition().x);
	float distanceY = abs(body.getPosition().y - other.body.getPosition().y);
	float separationX = distanceX - (body.getSize().x + other.body.getSize().x) / 2.0f;
	float separationY = distanceY - (body.getSize().y + other.body.getSize().y) / 2.0f;
	if (separationX <= 0.0f || separationY <= 0.0f)
		return true;
	return false;
}

#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	uvRect.width = texture->getSize().x / imageCount.x;
	uvRect.height = texture->getSize().y / imageCount.y;
	currentImage = sf::Vector2u(0, 0);
}

Animation::~Animation()
{
}

void Animation::Update(int row, bool faceRight, float deltaTime){
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime > switchTime) {
		currentImage.x++;
		totalTime -= switchTime;
		if (currentImage.x >= imageCount.x)
			currentImage.x = 0;
	}
	uvRect.top = currentImage.y * uvRect.height;
	uvRect.left = currentImage.x * uvRect.width;
}

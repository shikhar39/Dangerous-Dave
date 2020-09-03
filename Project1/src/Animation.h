#pragma once
#include <SFML/Graphics.hpp>

class Animation{
public:
	Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
	~Animation();
	
	void Update(int row, bool faceRight, float deltaTime);

	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float switchTime;
	float totalTime;
};


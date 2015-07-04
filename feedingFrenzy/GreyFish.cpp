#include "GreyFish.hpp"
#include <iostream>

#pragma region CONSTRUCTORS/DECONSTRUCTOR


GreyFish::GreyFish(sf::Texture* texture)
{
	this->setVelocity(0.1f + ((0.1f - 0.2f)*((float)rand() / RAND_MAX)) + 0.2f);
	this->setSize(0.4f);
	this->getSprite()->setTexture(*texture);
	this->getSprite()->setScale(-0.3f, 0.3f);
	this->setAlive(true);
	setBounds(&getBounds());
}
GreyFish::~GreyFish()
{}
#pragma endregion CONSTRUCTORS/DECONSTRUCTOR

void GreyFish::move()
{
	static int i = 0;
	i++;

	if (i % 3 == 0)
		getSprite()->move(-this->getVelocity(), -this->getVelocity());
	
	else if (i % 4 == 0)
		getSprite()->move(-this->getVelocity(), this->getVelocity());

	else
	this->getSprite()->move(-this->getVelocity(), 0);
	
	if (i == 1000)
		i = 0;
}


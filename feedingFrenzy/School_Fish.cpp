#include "School_Fish.hpp"
#include <iostream>

#pragma region CONSTRUCTORS/DECONSTRUCTOR

School_Fish::School_Fish(sf::Texture* texture) : Enemy()
{
	this->setSize(0.1f);
	this->setVelocity(0.2f + ((0.1f - 0.3f)*((float)rand() / RAND_MAX)) + 0.3f);
	this->setAlive(true);
	this->getSprite()->setScale(0.05f, 0.05f);
	this->getSprite()->setTexture(*texture);
	setBounds(&getBounds());

}

School_Fish::~School_Fish()
{}
#pragma endregion


void School_Fish::move()
{
	this->getSprite()->move(-this->getVelocity(), 0);
}

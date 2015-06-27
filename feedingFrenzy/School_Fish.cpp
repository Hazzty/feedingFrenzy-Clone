#include "School_Fish.hpp"
#include <iostream>

#pragma region CONSTRUCTORS/DECONSTRUCTOR

School_Fish::School_Fish(sf::Texture* texture) : Enemy()
{
	this->setSize(0.1);
	this->setVelocity(0.2 + ((0.1 - 0.3)*((float)rand() / RAND_MAX)) + 0.3);
	this->setAlive(true);
	this->getSprite()->setScale(0.05, 0.05);
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

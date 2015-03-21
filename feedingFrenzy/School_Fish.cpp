#include "School_Fish.hpp"
#include	<iostream>

School_Fish::School_Fish(float size, float velocity) : Enemy(size, velocity)
{
	this->getSprite()->setScale(0.1, 0.1);
	this->setTexture("../Resources/Textures/Fish/greyFish.png");
	this->getSprite()->setRotation(180);
	setBounds(&getBounds());

}

void School_Fish::move()
{

	std::cout << "hej";
}

School_Fish::~School_Fish()
{

}
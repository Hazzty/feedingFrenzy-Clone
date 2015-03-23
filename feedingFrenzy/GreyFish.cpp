#include "GreyFish.hpp"
#include <iostream>

#pragma region CONSTRUCTORS/DECONSTRUCTOR
GreyFish::GreyFish()
{
	this->setVelocity(0.1 + ((0.1 - 0.2)*((float)rand() / RAND_MAX)) + 0.2);
	this->setSize(0.4);
	this->setTexture("../Resources/Textures/Fish/greyFish.png");
	this->getSprite()->setScale(-0.3, 0.3);
	this->setAlive(true);
	setBounds(&getBounds());
}
GreyFish::~GreyFish()
{
	cout << "~GreyFish()" << endl;
}
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
}


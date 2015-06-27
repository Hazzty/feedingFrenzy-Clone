#ifndef GreyFish_HPP
#define GreyFish_HPP

#include "Enemy.hpp"

class GreyFish : public Enemy
{
public:
	GreyFish(sf::Texture* texture);
	virtual ~GreyFish();
	virtual void move();
};

#endif
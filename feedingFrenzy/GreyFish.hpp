#ifndef GreyFish_HPP
#define GreyFish_HPP

#include "Enemy.hpp"

class GreyFish : public Enemy
{
public:
	GreyFish();
	virtual ~GreyFish();
	virtual void move();
};

#endif
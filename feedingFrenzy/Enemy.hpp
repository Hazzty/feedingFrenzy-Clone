#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Fish.hpp"

class Enemy : public Fish
{
public:
	virtual void move() = 0;
	
	Enemy();
	virtual  ~Enemy();
private:

};

#endif
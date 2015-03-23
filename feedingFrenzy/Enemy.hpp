#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Fish.hpp"

class Enemy : public Fish
{
public:
	Enemy();
	virtual  ~Enemy();

	virtual void move() = 0;
private:

};

#endif
#ifndef SCHOOL_FISH_HPP
#define SCHOOL_FISH_HPP

#include "Enemy.hpp"
class School_Fish : public Enemy
{
public:
	School_Fish(sf::Texture* texture);
	virtual ~School_Fish();
	virtual void move();
};

#endif
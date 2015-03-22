#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Fish.hpp"

class Enemy : public Fish
{
public:
	Enemy();
	virtual  ~Enemy();
	virtual void move() = 0;
	int getX() const;
	void setX(int x);

	int getY() const;
	void setY(int y);
private:
	int x;
	int y;
};

#endif
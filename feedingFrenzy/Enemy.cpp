#include "Enemy.hpp"
Enemy::Enemy(float size, float velocity)
	:Fish(size, velocity)
{
	
}

int Enemy::getX() const
{
	return this->x;
}
void Enemy::setX(int x)
{
	this->x = x;
}

int Enemy::getY() const
{
	return this->y;
}
void Enemy::setY(int y)
{
	this->y = y;
}
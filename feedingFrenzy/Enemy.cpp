#include "Enemy.hpp"

#pragma region CONSTRUCTORS/DECONSTRUCTOR
Enemy::Enemy() : Fish()
{

}
Enemy::~Enemy()
{

}
#pragma endregion CONSTRUCTORS/DECONSTRUCTOR

#pragma region ACCESSORS/MODIFIERS
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
#pragma endregion ACCESSORS/MODIFIERS
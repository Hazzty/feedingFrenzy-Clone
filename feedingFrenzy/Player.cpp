#include "Player.hpp"
bool Player::setScore(int value)
{
	bool result = true;
	if (!(this->score = value))
		result = false;
	return result;
}
int Player::getScore() const
{
	return this->score;
}

bool Player::setFishEaten(int value)
{
	bool result = true;
	if (!(this->fishEaten = value))
		result = false;
	return result;
}
int Player::getFishEaten() const
{
	return this->fishEaten;
}

bool Player::setHealth(int value)
{
	bool result = true;
	if (!(this->health = value))
		result = false;
	return result;
}
int Player::getHealth() const
{
	return this->health;
}

Player::Player() 
	:Fish()
{
	this->health = 3;
	this->score = 0;
	this->fishEaten = 0;
}
Player::~Player()
{

}
#include "Player.hpp"
#include <vector>
#pragma region CONSTRUCTORS/DECONSTRUCTOR
Player::Player() 
	:Fish()
{
	this->setSize(1.0);
	this->health = 3;
	this->score = 0;
	this->fishEaten = 0;
}
Player::~Player()
{

}
#pragma endregion 

void Player::eat(vector<Fish*> *fishes, int index)
{
	this->score += fishes->at(index)->getSize() * 10;
	this->fishEaten++;
	fishes->erase(fishes->begin() + index);

}

#pragma region ACCESSORS/MODIFIERS
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
#pragma endregion

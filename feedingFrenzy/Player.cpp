#include "Player.hpp"
#include <vector>
#include <iostream>

#pragma region CONSTRUCTORS/DECONSTRUCTOR
Player::Player(float size, float velocity)
{
	this->setSize(size);
	this->setVelocity(velocity);

	this->setTexture("../Resources/Textures/Fish/playerFish.png");
	this->getSprite()->setScale(0.1f, 0.1f);
	this->getSprite()->setOrigin(this->getSprite()->getTexture()->getSize().x / 2, this->getSprite()->getTexture()->getSize().y / 2);
	this->setAlive(true);
	this->score = 0;
	this->fishEaten = 0;

}

Player::Player()
{
	this->setSize(0.2f);
	this->setVelocity(0.01f);

	this->setTexture("../Resources/Textures/Fish/playerFish.png");
	this->getSprite()->setScale(0.1f, 0.1f);
	this->getSprite()->setOrigin((float)(this->getSprite()->getTexture()->getSize().x / 2), (float)(this->getSprite()->getTexture()->getSize().y / 2));
	this->setAlive(true);
	this->score = 0;
	this->fishEaten = 0;
}

Player::~Player()
{
}
#pragma endregion 

void Player::eat(vector<Fish*> *fishes, int index)
{
	this->fishEaten++;
	this->score += 1 * fishEaten;

	delete fishes->at(index);
	fishes->erase(fishes->begin() + index);

	if (fishEaten % 10 == 0) //Grow every 10th fish
	{
		this->setSize(this->getSize() + 0.1f);
		if (this->getSize() < 1.0f)
		{
			if (isFlipped)	//handle player's facing
				this->getSprite()->setScale(-this->getSize(), this->getSize());
			else
				this->getSprite()->setScale(this->getSize(), this->getSize());
		}
	}
}

void Player::move()
{
	//Here be dragons.
}

#pragma region ACCESSORS/MODIFIERS
void Player::setIsFlipped(bool isFlipped)
{
	this->isFlipped = isFlipped;
}
bool Player::getIsFlipped() const
{
	return this->isFlipped;
}

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

float Player::getMaxSpeed()
{
	return this->maxSpeed;
}
void Player::setMaxSpeed(float speed)
{
	this->maxSpeed = speed;
}

float Player::getCurrSpeedX()
{
	return this->currSpeedX;
}
void Player::setCurrSpeedX(float speed)
{
	this->currSpeedX = speed;
}

float Player::getCurrSpeedY()
{
	return this->currSpeedY;
}
void Player::setCurrSpeedY(float speed)
{
	this->currSpeedY = speed;
}

#pragma endregion

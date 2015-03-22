#include "Player.hpp"
#include <vector>

#pragma region CONSTRUCTORS/DECONSTRUCTOR
Player::Player(float size, float velocity)
{
	this->setSize(size);
	this->setVelocity(velocity);

	this->setTexture("../Resources/Textures/Fish/playerFish.png");
	this->getSprite()->setScale(0.1, 0.1);
	this->getSprite()->setOrigin(this->getSprite()->getTexture()->getSize().x / 2, this->getSprite()->getTexture()->getSize().y / 2);
	this->alive = true;
	this->score = 0;
	this->fishEaten = 0;

}

Player::Player()
{
	this->setSize(0.2);
	this->setVelocity(0.2);

	this->setTexture("../Resources/Textures/Fish/playerFish.png");
	this->getSprite()->setScale(0.1, 0.1);
	this->getSprite()->setOrigin(this->getSprite()->getTexture()->getSize().x / 2, this->getSprite()->getTexture()->getSize().y / 2);
	this->alive = true;
	this->score = 0;
	this->fishEaten = 0;
}

Player::~Player()
{

}
#pragma endregion 

void Player::eat(vector<Fish*> *fishes, int index)
{
	this->score += 1 * fishEaten;
	this->fishEaten++;
	fishes->erase(fishes->begin() + index);
	
	if (fishEaten % 10 == 0)
	{
		this->setSize(this->getSize() + 0.1f);
		if (this->getSize() < 1.0f)
		{
			if (isFlipped)
				this->getSprite()->setScale(-this->getSize(), this->getSize());
			else
				this->getSprite()->setScale(this->getSize(), this->getSize());
		}
	}
}

void Player::move()
{
	//These are not the droids you're looking for.
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

void Player::setAlive(bool value)
{
	this->alive = value;
}
bool Player::getAlive() const
{
	return this->alive;
}
#pragma endregion

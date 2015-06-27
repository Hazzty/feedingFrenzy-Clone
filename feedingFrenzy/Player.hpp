#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Fish.hpp"

class Player : public Fish 
{
private:
	int score,
		fishEaten;
	float maxSpeed = 1.0f;
	float currSpeedX = 0.0f;
	float currSpeedY = 0.0f;
	bool isFlipped = false;

public:


	Player(float size, float velocity);
	Player();
	virtual ~Player();

	void eat(vector<Fish*> *fishes, int index);

	void accelerate(int dir);

	float getCurrSpeedY();
	void setCurrSpeedY(float speed);
	float getCurrSpeedX();
	void setCurrSpeedX(float speed);

	float getMaxSpeed();
	void setMaxSpeed(float speed);

	void setIsFlipped(bool isFlipped);
	bool getIsFlipped() const;

	bool setScore(int value);
	int getScore() const;

	bool setFishEaten(int value);
	int getFishEaten() const;

	virtual void move(); 
};


#endif
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Fish.hpp"

class Player : public Fish 
{
private:
	int score,
		fishEaten,
		health;
public:
	bool setScore(int value);
	int getScore() const;

	bool setFishEaten(int value);
	int getFishEaten() const;

	bool setHealth(int value);
	int getHealth() const;

	Player();
	virtual ~Player();
};


#endif
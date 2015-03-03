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

	void eat(vector<Fish*> *fishes, int index);

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
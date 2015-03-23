#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Fish.hpp"

class Player : public Fish 
{
private:
	int score,
		fishEaten;
	bool isFlipped = false;

public:

	Player(float size, float velocity);
	Player();
	virtual ~Player();

	void eat(vector<Fish*> *fishes, int index);

	void setIsFlipped(bool isFlipped);
	bool getIsFlipped() const;

	bool setScore(int value);
	int getScore() const;

	bool setFishEaten(int value);
	int getFishEaten() const;

	virtual void move(); 
};


#endif
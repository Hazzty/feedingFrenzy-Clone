#include "Fish.hpp"

class Enemy : public Fish
{
public:
	Enemy(float size, float velocity);
	virtual void move() = 0;
	int getX() const;
	void setX(int x);

	int getY() const;
	void setY(int y);
private:
	int x;
	int y;
};
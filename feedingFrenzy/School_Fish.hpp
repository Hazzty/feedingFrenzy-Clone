#include "Enemy.hpp"
class School_Fish : public Enemy
{
public:
	School_Fish(float size, float velocity);
	virtual void move();
	virtual ~School_Fish();
};
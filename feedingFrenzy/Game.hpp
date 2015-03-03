#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include <vector>

class Game : public sf::Drawable
{
public:
	Game();
	~Game();

	void Update(float dt);

	Fish* getFishes();

	bool setFishAmount(int value);
	int getFishAmount() const;

	bool addFish(Fish* f);
	bool removeFish(Fish* f);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	int fishAmount;
	vector<Fish*> fishes;
	Player* player;


};
#endif
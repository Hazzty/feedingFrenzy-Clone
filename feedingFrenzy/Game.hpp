#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"

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
	Fish* fish;
	Player* player;


};
#endif
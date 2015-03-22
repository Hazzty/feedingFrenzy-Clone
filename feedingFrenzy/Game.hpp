#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include <vector>

class Game : public sf::Drawable
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	void Update(float dt, sf::RenderWindow *window);

	Fish* getFishes() const;

	bool setFishAmount(int value);
	int getFishAmount() const;

	bool addFish(Fish* f);
	bool removeFish(Fish* f);

	sf::View getCamera() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	int fishAmount;
	vector<Fish*> fishes;
	Player* player;
	sf::Font font;
	sf::Text fishEatenText
		, aliveText
		,scoreText;
};
#endif
#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
Game::Game()
{
	player = new Player();
	fishAmount = 3;
	fish = new Fish[fishAmount];

	for (int i = 0; i < fishAmount; i++)
	{
		fish[i].getSprite()->setPosition(600 + i * 50, 100 + i * 50);
		sf::FloatRect bound = fish[i].getSprite()->getGlobalBounds();
		fish[i].setBounds(bound);
	}
	
}

Game::~Game()
{

}

void Game::Update(float dt)
{

	for (int i = 0; i < fishAmount; i++)
	{
		fish[i].getSprite()->move(-(fish[i].getVelocity()*dt), 0);
		sf::FloatRect bound = fish[i].getSprite()->getGlobalBounds();
		fish[i].setBounds(bound);
		if (fish[i].getBounds().intersects(player->getBounds()))
			std::cout << "kollision" << endl;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player->getSprite()->move(-(player->getVelocity() *dt), 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player->getSprite()->move((player->getVelocity() *dt), 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player->getSprite()->move(0, (player->getVelocity() *dt));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player->getSprite()->move(0, -(player->getVelocity() *dt));
	
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*player->getSprite(), states);
	for (int i = 0; i < fishAmount; i++)
		target.draw(*fish[i].getSprite(), states);
}

#pragma region ACCESSORS/MODIFIERS
Fish* Game::getFishes()
{
	return this->fish;
}

bool Game::setFishAmount(int value)
{
	bool result = true;

	if (!(this->fishAmount = value))
		result = false;
	return result;
}
int Game::getFishAmount() const
{
	return this->fishAmount;
}

bool Game::addFish(Fish* f)
{
	return true;
}
bool removeFish(Fish* f)
{
	return true;
}
#pragma endregion
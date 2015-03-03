#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

Game::Game()
{
	
	fishAmount = 3;
	
	for (int i = 0; i < fishAmount; i++)
	{
		fishes.push_back(new Fish());
		fishes.at(i)->getSprite()->setPosition(600 + i * 50, 200 + i * 50);
	}
	player = new Player();
}

Game::~Game()
{

}

void Game::Update(float dt)
{

	for (int i = 0; i < fishes.size(); i++)
	{
		fishes.at(i)->getSprite()->move(-0.01f*dt, 0);

		if (fishes.at(i)->getBounds().intersects(player->getBounds())
			&& fishes.at(i)->getAlive() == true)
		{
			if (fishes.at(i)->getSize() <= player->getSize())
			{
				player->eat(&fishes, i);
				std::cout << "eaten" << endl;
			}

			std::cout << "kollision" << endl;
		}
			
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player->getSprite()->move(-player->getVelocity() *dt, 0);
	//s	player->setVelocity(player->getVelocity()+0.02f);
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player->getSprite()->setRotation(180);
		player->getSprite()->move(player->getVelocity() *dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player->getSprite()->move(0, player->getVelocity() *dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player->getSprite()->move(0, -player->getVelocity() *dt);
	
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*player->getSprite(), states);
	for (int i = 0; i < fishes.size(); i++)
	{
		if (fishes.at(i)->getAlive() == true)
		target.draw(*fishes.at(i)->getSprite(), states);
	}
		
}

#pragma region ACCESSORS/MODIFIERS


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
bool Game::removeFish(Fish* f)
{
	Fish* tmp = new Fish[fishAmount-1];
	
	return true;
}
#pragma endregion
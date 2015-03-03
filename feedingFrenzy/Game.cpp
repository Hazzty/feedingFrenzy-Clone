#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

Game::Game()
{
	fishAmount = 10;

	for (int i = 0; i < fishAmount; i++)
	{
		fishes.push_back(new Fish());
		fishes.at(i)->getSprite()->setPosition(i * 50, i * 50);
	}
	player = new Player();
	player->getSprite()->setOrigin(player->getSprite()->getTexture()->getSize().x / 2, player->getSprite()->getTexture()->getSize().y / 2);
}

Game::~Game()
{

}

void Game::Update(float dt, sf::RenderWindow *window)
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
#pragma region INPUT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (player->getSprite()->getPosition().x > 0)
		player->getSprite()->move(-player->getVelocity() *dt, 0);
		player->getSprite()->setRotation(0);
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player->getSprite()->setRotation(180);
		if (player->getSprite()->getPosition().x + (player->getSprite()->getTexture()->getSize().x/2) < window->getSize().x)
		player->getSprite()->move(player->getVelocity() *dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (player->getSprite()->getPosition().y < window->getSize().y)
		player->getSprite()->move(0, player->getVelocity() *dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (player->getSprite()->getPosition().y > 0)
		player->getSprite()->move(0, -player->getVelocity() *dt);

	}
#pragma endregion INPUT
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
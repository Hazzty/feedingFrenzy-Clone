#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "School_Fish.hpp"
#include "GreyFish.hpp"
#include "Includes.hpp"

#pragma region CONSTRUCTORS/DECONSTRUCTOR

Game::Game(sf::RenderWindow& window)
{
	fishAmount = 100;
	fishes.reserve(fishes.size() + 1);

	for (int i = 0; i < fishAmount; i++)
	{
		if (i < fishAmount / 5)
		{
			fishes.push_back(new GreyFish());
		}
		else
			fishes.push_back(new School_Fish());

		fishes.back()->getSprite()->setPosition(rand() % window.getSize().x + 1, rand() % window.getSize().y + 1);
	}
	player = new Player(0.1, 0.2);
	player->getSprite()->setPosition(rand() % 800 + 1, rand() % 600 + 1);
	
#pragma region FONTS
	if (!font.loadFromFile("../Resources/Fonts/calibri.ttf"))
		cout << "Failed to load font.";

	fishEatenText.setFont(font);
	scoreText.setFont(font);
	aliveText.setFont(font);

	fishEatenText.setPosition(100, 0);
	scoreText.setPosition(300, 0);
	aliveText.setPosition(500, 0);

	fishEatenText.setCharacterSize(24);
	scoreText.setCharacterSize(24);
	aliveText.setCharacterSize(24);

	fishEatenText.setString("Fish eaten: " + intToStr(player->getFishEaten()));
	scoreText.setString("Score: " + intToStr(player->getScore()));
	aliveText.setString("");

#pragma endregion FONTS
}

Game::~Game()
{
	
	for (int i = 0; i < fishes.size(); i++)
		delete fishes.at(i);

	delete player;
}

#pragma endregion CONSTRUCTORS/DECONSTRUCTOR

void Game::Update(float dt, sf::RenderWindow *window)
{

#pragma region TEXT

	fishEatenText.setString("Fish eaten: " + intToStr(player->getFishEaten()));
	scoreText.setString("Score: " + intToStr(player->getScore()));

	if (!player->getAlive())
	aliveText.setString("GAME OVER");
	
#pragma endregion TEXT

#pragma region GAME LOGIC
	if (player->getAlive() > 0){

		for (int i = 0; i < fishes.size(); i++)
		{
			fishes.at(i)->move();

			if (fishes.at(i)->getBounds().intersects(player->getBounds()))
			{
				if (fishes.at(i)->getSize() <= player->getSize())
					player->eat(&fishes, i);
				else
					player->setAlive(false);
					
				std::cout << "Collision" << endl;
			}

			if (fishes.at(i)->getSprite()->getPosition().x < 0)
			{
				fishes.erase(fishes.begin() + i);
				fishes.shrink_to_fit();
			}

		}
		while (fishes.size() < 100)
		{
			int fishToSpawn = rand() % 100;

				
			if(fishToSpawn % 9 == 0)
				fishes.push_back(new GreyFish());
			else
				fishes.push_back(new School_Fish());


			fishes.back()->getSprite()->setPosition(window->getSize().x + rand() % 100, rand() % window->getSize().y);
		}

#pragma endregion GAME LOGIC

#pragma region INPUT

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player->getSprite()->getPosition().x >= 0)
		{
			player->getSprite()->move(-player->getVelocity() *dt, 0);
			if (player->getIsFlipped())
			{
				player->getSprite()->setScale(-player->getSprite()->getScale().x, player->getSprite()->getScale().y);
				player->setIsFlipped(false);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player->getSprite()->getPosition().x <= window->getSize().x)
		{
			player->getSprite()->move(player->getVelocity() *dt, 0);
			if (!player->getIsFlipped())
			{
				player->getSprite()->setScale(-player->getSprite()->getScale().x, player->getSprite()->getScale().y);
				player->setIsFlipped(true);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player->getSprite()->getPosition().y <= window->getSize().y)
		{
			player->getSprite()->move(0, player->getVelocity() *dt);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player->getSprite()->getPosition().y >= 0)
		{
			player->getSprite()->move(0, -player->getVelocity() *dt);
		}
		
	}
#pragma endregion INPUT
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*player->getSprite(), states);
	for (int i = 0; i < fishes.size(); i++)
		target.draw(*fishes.at(i)->getSprite(), states);
		
	target.draw(fishEatenText, states);
	target.draw(scoreText, states);
	target.draw(aliveText, states);
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

#pragma endregion
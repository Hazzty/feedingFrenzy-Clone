#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "School_Fish.hpp"
#include "GreyFish.hpp"
#include "Includes.hpp"

#pragma region CONSTRUCTORS/DECONSTRUCTOR

sf::Texture texture[2];

Game::Game(sf::RenderWindow& window)
{

	texture[0].loadFromFile("../Resources/Textures/Fish/greyFish.png");
	texture[0].setSmooth(true);
	texture[1].loadFromFile("../Resources/Textures/Fish/redFish.png");
	texture[1].setSmooth(true);

	fishAmount = 100;
	fishes.reserve(fishes.size() + 1);

	for (int i = 0; i < fishAmount; i++)
	{
		if (i < fishAmount / 5)
		{
			fishes.push_back(new GreyFish(&texture[0]));
		}
		else
			fishes.push_back(new School_Fish(&texture[1]));

		fishes.back()->getSprite()->setPosition((float)(rand() % window.getSize().x + 1), (float)(rand() % window.getSize().y + 1));
	}
	player = new Player();
	player->getSprite()->setPosition((float)(rand() % 800 + 1), (float)(rand() % 600 + 1));

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
	for (unsigned int i = 0; i < fishes.size(); i++)
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
	if (!player->getAlive())
	{
		player->getSprite()->setPosition((float)(rand() % 800 + 1), (float)(rand() % 600 + 1));
		player->getSprite()->setScale(0.1f, 0.1f);
		player->setSize(0.2f);
		player->setScore(0);
		player->setFishEaten(0);
		player->setCurrSpeedX(0.0f);
		player->setCurrSpeedY(0.0f);
		player->setVelocity(0.01f);
		player->setIsFlipped(false);
		player->setAlive(true);
	}
	//Handle player moving outside the viewport
	if (player->getSprite()->getPosition().y < 0)
		player->getSprite()->setPosition(player->getSprite()->getPosition().x, window->getSize().y);
	else if (player->getSprite()->getPosition().y > window->getSize().y)
		player->getSprite()->setPosition(player->getSprite()->getPosition().x, 0);
	else if (player->getSprite()->getPosition().x < 0)
		player->getSprite()->setPosition(window->getSize().x, player->getSprite()->getPosition().y);
	else if (player->getSprite()->getPosition().x > window->getSize().x)
		player->getSprite()->setPosition(0, player->getSprite()->getPosition().y);


	player->getSprite()->move(player->getCurrSpeedX() *dt, 0.0f);
	player->getSprite()->move(0.0f, player->getCurrSpeedY() *dt);

	for (unsigned int i = 0; i < fishes.size(); i++) //Move all the fishes and check for collisions
	{
		fishes.at(i)->move();

		if (fishes.at(i)->getBounds().intersects(player->getBounds()))
		{
			if (fishes.at(i)->getSize() <= player->getSize())
				player->eat(&fishes, i);
			//else
				//player->setAlive(false);
		}

		else if (fishes.at(i)->getSprite()->getPosition().x < 0) // When a fish swims off the screen
		{
			delete fishes.at(i);
			fishes.erase(fishes.begin() + i);
		}

	}

	while (fishes.size() < fishAmount) //Fish spawning
	{
		int fishToSpawn = rand() % 100;

		if (fishToSpawn % 9 == 0)
		{
			fishes.push_back(new GreyFish(&texture[0]));
			fishes.shrink_to_fit();
		}
		else
		{
			fishes.push_back(new School_Fish(&texture[1]));
			fishes.shrink_to_fit();
		}


		fishes.back()->getSprite()->setPosition((float)(window->getSize().x + rand() % 50 + 70), (float)(rand() % window->getSize().y));
	}

#pragma endregion GAME LOGIC

#pragma region INPUT

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //Reset speed and position
	{
		player->getSprite()->setPosition(window->getSize().x / 2, window->getSize().y / 2);
		player->setCurrSpeedX(0.0f);
		player->setCurrSpeedY(0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (player->getCurrSpeedX() > -player->getMaxSpeed())
			player->setCurrSpeedX((player->getCurrSpeedX() - player->getVelocity()));
		if (player->getCurrSpeedX() < -player->getMaxSpeed())
			player->setCurrSpeedX(-player->getMaxSpeed());

		if (player->getIsFlipped())
		{
			player->getSprite()->setScale(-player->getSprite()->getScale().x, player->getSprite()->getScale().y);
			player->setIsFlipped(false);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (player->getCurrSpeedX() < player->getMaxSpeed())
			player->setCurrSpeedX((player->getCurrSpeedX() + player->getVelocity()));

		if (!player->getIsFlipped())
		{
			player->getSprite()->setScale(-player->getSprite()->getScale().x, player->getSprite()->getScale().y);
			player->setIsFlipped(true);
		}
	}
	else
	{
		if (player->getCurrSpeedX() > 0.0f)
			player->setCurrSpeedX(player->getCurrSpeedX() - player->getVelocity());
		else if (player->getCurrSpeedX() < 0.0f)
			player->setCurrSpeedX(player->getCurrSpeedX() + player->getVelocity());
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (player->getCurrSpeedY() > player->getMaxSpeed())
			player->setCurrSpeedY(player->getMaxSpeed());
		else
			player->setCurrSpeedY((player->getCurrSpeedY() + player->getVelocity()));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (player->getCurrSpeedY() > -player->getMaxSpeed())
			player->setCurrSpeedY((player->getCurrSpeedY() - player->getVelocity()));
	}
	else
	{
		if (player->getCurrSpeedY() > 0.0f)
			player->setCurrSpeedY(player->getCurrSpeedY() - player->getVelocity());
		else if (player->getCurrSpeedY() < 0.0f)
			player->setCurrSpeedY(player->getCurrSpeedY() + player->getVelocity());
	}


#pragma endregion INPUT

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*player->getSprite(), states);
	for (unsigned int i = 0; i < fishes.size(); i++)
		target.draw(*fishes.at(i)->getSprite(), states);

	target.draw(fishEatenText, states);
	target.draw(scoreText, states);
	target.draw(aliveText, states);
}
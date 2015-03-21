#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>
#include "School_Fish.hpp"
#include "Includes.hpp"

Game::Game(sf::RenderWindow& window)
{


	fishAmount = 100;

	for (int i = 0; i < fishAmount; i++)
	{
		fishes.push_back(new School_Fish(0.09, 1.0));
		fishes.at(i)->getSprite()->setPosition(rand() % 800+1, rand() % 600 + 1);
	}
	player = new Player(0.1, 0.2);
	player->getSprite()->setOrigin(player->getSprite()->getTexture()->getSize().x / 2, player->getSprite()->getTexture()->getSize().y / 2);

#pragma region FONTS
	if (!font.loadFromFile("../Resources/Fonts/calibri.ttf"))
		cout << "Failed to load font.";

	fishEatenText.setFont(font);
	scoreText.setFont(font);
	healthText.setFont(font);

	fishEatenText.setPosition(0,0);
	scoreText.setPosition(200, 0);
	healthText.setPosition(300, 0);

	fishEatenText.setCharacterSize(24);
	scoreText.setCharacterSize(24);
	healthText.setCharacterSize(24);

	fishEatenText.setString("Fish eaten: " + intToStr(player->getFishEaten()));
	scoreText.setString("Score: " + intToStr(player->getScore()));
	healthText.setString("Health: " + intToStr(player->getHealth()));

#pragma endregion FONTS
}

Game::~Game()
{
	delete[] &fishes;
}

void Game::Update(float dt, sf::RenderWindow *window)
{

#pragma region CAMERA
	/*camera.reset(sf::FloatRect(200 + (player->getSize() * 50), 200 + (player->getSize() * 50), 300, 200 + (player->getSize() * 50)));
	camera.setCenter(sf::Vector2f(player->getSprite()->getPosition().x, player->getSprite()->getPosition().y));
	window->setView(camera);*/
#pragma endregion CAMERA

#pragma region TEXT

	fishEatenText.setString("Fish eaten: " + intToStr(player->getFishEaten()));
	scoreText.setString("Score: " + intToStr(player->getScore()));
	healthText.setString("Health: " + intToStr(player->getHealth()));
	
#pragma endregion TEXT

#pragma region GAME LOGIC
	for (int i = 0; i < fishes.size(); i++)
	{
		fishes.at(i)->getSprite()->move(-0.01f*dt, 0);

		if (fishes.at(i)->getBounds().intersects(player->getBounds()))
		{
			if (fishes.at(i)->getSize() < player->getSize())
			{
				player->eat(&fishes, i);
			
			}

			std::cout << "kollision" << endl;
		}
			
	}
	//while (fishes.size() < 50)
	//{
	////	fishes.push_back(new School_Fish(1.0, 1.0));
	////	fishes.at(i)->getSprite()->setPosition(rand() % 800 + 1, rand() % 600 + 1);
	//}

#pragma endregion GAME LOGIC

#pragma region INPUT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//if (player->getSprite()->getPosition().x - (player->getSprite()->getTexture()->getSize().x) > 0)
		player->getSprite()->move(-player->getVelocity() *dt, 0);
		player->getSprite()->setRotation(0);
		//player->getSprite()->setTextureRect(sf::IntRect(player->getSprite()->getTextureRect, 0, -width, height));
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player->getSprite()->setRotation(180);
	//	player->getSprite()->setScale(-1.0f, -1.0f);
		//if (player->getSprite()->getPosition().x + (player->getSprite()->getTexture()->getSize().x) < window->getSize().x)
		player->getSprite()->move(player->getVelocity() *dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	//	if (player->getSprite()->getPosition().y - (player->getSprite()->getTexture()->getSize().y) < window->getSize().y)
		player->getSprite()->move(0, player->getVelocity() *dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	//	if (player->getSprite()->getPosition().y > 0)
		player->getSprite()->move(0, -player->getVelocity() *dt);

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
	target.draw(healthText, states);
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
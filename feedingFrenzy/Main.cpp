
#pragma region EXTERNALS

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
#pragma endregion EXTERNALS
int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Game* game = new Game(window);
	sf::Clock gameTime;
	window.setVerticalSyncEnabled(true);
	

	while (window.isOpen())
	{
		/*
		unsigned int frameCounter = 0;
		unsigned int frameTime = 0;
		unsigned int fps = 0;
		frameCounter++;
		frameTime += gameTime.getElapsedTime().asMilliseconds();
		if (frameTime >= 1000)
		{
			fps = frameCounter;
			frameCounter = 0;
			frameTime -= 1000;
		}
		cout << "FPS: " << fps;
		system("cls");
		*/

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		game->Update(gameTime.restart().asMilliseconds(), &window);
		
		sf::Color color(0, 50, 255);
		window.clear(color);			 
		window.draw(*game);
		window.display();
	}

	return 0;
}

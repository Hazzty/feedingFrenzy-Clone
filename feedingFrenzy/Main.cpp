
#pragma region EXTERNALS

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
#pragma endregion
int main()
{
	Game game;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Clock gameTime;
	
	Fish* fishes = game.getFishes();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		game.Update(gameTime.restart().asMilliseconds());
		
		sf::Color color(0, 50, 255);
		window.clear(color);			 
		window.draw(game);
		window.display();
	}

	return 0;
}

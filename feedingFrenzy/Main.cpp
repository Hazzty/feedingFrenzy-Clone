#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Feeding Frenzy");
	window.setFramerateLimit(144);
	Game* game = new Game(window);
	window.requestFocus();
	sf::Clock gameTime;
	window.setVerticalSyncEnabled(true);
	

	while (window.isOpen())
	{
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
	delete game;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}

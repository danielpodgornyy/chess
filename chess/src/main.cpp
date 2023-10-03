#include <iostream>
#include <sstream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920,1080), "Chess", sf::Style::Fullscreen);

	Game currGame;
	

	sf::Vector2i mouseWinPos;
	sf::Vector2u mouseGridPos;


	currGame.InitBoard();
	currGame.InitText();

	while (window.isOpen())
	{
		sf::Event currEvent;

		while (window.pollEvent(currEvent))
		{
			if (currEvent.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//mouseWinPos = sf::Mouse::getPosition(window);
		//mouseGridPos.x = mouseWinPos.x / unsigned_tileSize;
		//mouseGridPos.y = mouseWinPos.y / unsigned_tileSize;
	


		window.clear(sf::Color(28,28,28));

		currGame.BuildBoard(window);
		currGame.BuildText(window);
		window.display();
	}

	return 0;
}
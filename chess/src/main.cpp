#include <iostream>
#include <sstream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920,1080), "Chess", sf::Style::Default);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Game currGame;
	

	sf::Vector2i mouseWinPos;


	currGame.InitBoard();
	currGame.InitText();
	currGame.InitCharArray();
	
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

		mouseWinPos = sf::Mouse::getPosition(window);

		currGame.SelectSquare(mouseWinPos);

		//Clear
		window.clear(sf::Color(28,28,28));

		//Build Game Board
		currGame.BuildBoard(window);
		currGame.BuildText(window);
		currGame.BuildCharArray(window);

		//Display
		window.display();
	}

	return 0;
}
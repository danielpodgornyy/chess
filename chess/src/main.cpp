#include <iostream>
#include <sstream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920,1080), "Chess", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Game currGame;
	
	//Mouse Position
	sf::Vector2i mouseWinPos;

	bool elementSelected = false;

	//Initiallize game
	currGame.InitBoard();
	currGame.InitText();
	currGame.InitCharArray();
	
	while (window.isOpen())
	{
		sf::Event currEvent;

		mouseWinPos = sf::Mouse::getPosition(window);

		while (window.pollEvent(currEvent))
		{
			if (currEvent.type == sf::Event::Closed)
			{
				window.close();
			}
			
			//Movement Keys
			if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::W)
			{
				currGame.SelectSquare('W');
			}
			else if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::A)
			{
				currGame.SelectSquare('A');
			}
			else if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::S)
			{
				currGame.SelectSquare('S');
			}
			else if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::D)
			{
				currGame.SelectSquare('D');
			}
			else if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::Enter)
			{
				if (elementSelected == false)
				{
					currGame.EnterSquare();
					elementSelected = true;
				}
				else
				{
					currGame.MakeMove();
					elementSelected = false;
				}
			}
		}

		//if (currGame.get)

		//Clear
		window.clear(sf::Color(28,28,28));

		//Build Game Board
		currGame.BuildBoard(window);
		currGame.BuildText(window);
		currGame.BuildCharArray(window);
		currGame.BuildOptions(window);

		//Display
		window.display();
	}

	return 0;
}
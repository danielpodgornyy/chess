#include <iostream>
#include <sstream>
#include "Board.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920,1080), "Chess", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Board chessBoard;
	
	//Mouse Position
	sf::Vector2i mouseWinPos;

	bool elementSelected = false;

	//Initialize game
	chessBoard.InitBoard();
	chessBoard.InitText();
	chessBoard.InitCharArray();
	
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
				chessBoard.SelectSquare('W');
			}
			else if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::A)
			{
				chessBoard.SelectSquare('A');
			}
			else if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::S)
			{
				chessBoard.SelectSquare('S');
			}
			else if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::D)
			{
				chessBoard.SelectSquare('D');
			}
			else if (currEvent.type == currEvent.KeyReleased && currEvent.key.code == sf::Keyboard::Enter)
			{
				chessBoard.Decide();
			}
		}

		//if (currGame.get)

		//Clear
		window.clear(sf::Color(28,28,28));

		//Build Game Board
		chessBoard.BuildBoard(window);
		chessBoard.BuildText(window);
		chessBoard.BuildCharArray(window);
		chessBoard.BuildOptions(window);

		//Display
		window.display();
	}

	return 0;
}
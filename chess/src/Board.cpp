#include "Board.h"

void Board::InitBoard()
{
	bool color = true; //true for white, false for black
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tileArray[i][j].setSize(sf::Vector2f(DEFAULT_SIZEf, DEFAULT_SIZEf));

			if (color)
			{
				tileArray[i][j].setFillColor(sf::Color::White);
			}
			else
			{
				tileArray[i][j].setFillColor(sf::Color::Black);
			}
			tileArray[i][j].setPosition(sf::Vector2f(i * DEFAULT_SIZEf + 560.f, j * DEFAULT_SIZEf + 140.f));
			
			color = !color;
		}
		color = !color;
	}
}

void Board::BuildBoard(sf::RenderWindow &inputWindow)
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			inputWindow.draw(tileArray[i][j]);
		}
	}
}

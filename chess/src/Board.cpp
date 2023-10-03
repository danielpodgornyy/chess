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
				tileArray[i][j].setFillColor(sf::Color(207,207,207));
			}
			else
			{
				tileArray[i][j].setFillColor(sf::Color(18, 18, 18));
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

void Board::InitCharArray()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 6)
			{
				charArray[i][j] = new Pawn;
			}
			else if (j == 7)
			{
				switch (i)
				{
				case 0:
					charArray[i][j] = new Rook;
					break;
				case 1:
					charArray[i][j] = new Knight;
					break;
				case 2:
					charArray[i][j] = new Bishop;
					break;
				case 3:
					charArray[i][j] = new Queen;
					break;
				case 4:
					charArray[i][j] = new King;
					break;
				case 5:
					charArray[i][j] = new Bishop;
					break;
				case 6:
					charArray[i][j] = new Knight;
					break;
				case 7:
					charArray[i][j] = new Rook;
					break;
				}
			}
			else
			{
				charArray[i][j] = new ChessChar;
			}
			charArray[i][j]->InitSprite();
			charArray[i][j]->SetPos(i * DEFAULT_SIZEf + 560.f, j * DEFAULT_SIZEf + 140.f);
		}
	}
}

void Board::BuildCharArray(sf::RenderWindow& inputWindow)
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			inputWindow.draw(charArray[i][j]->GetSprite());
		}
	}
}


void Board::SelectSquare(sf::Vector2i mousePos)
{
	sf::Vector2u gridPos(mousePos.x / unsigned_DEFAULT_SIZE - 560.f, mousePos.y / unsigned_DEFAULT_SIZE - 140.f);


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (gridPos == static_cast<sf::Vector2u>(charArray[i][j]->GetSprite().getPosition()))
			{
				charArray[i][j]->GetSprite().setRotation(2);
			}
		}
	}
	
}

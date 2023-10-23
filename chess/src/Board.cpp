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

void Board::InitText()
{
	font.loadFromFile("OpenSans-Bold.ttf");

	title.setCharacterSize(30);
	title.setFillColor(sf::Color::White);
	title.setPosition(20.f, 20.f);
	title.setFont(font);
	title.setString("CHESS");
}

void Board::BuildText(sf::RenderWindow& inputWindow)
{
	inputWindow.draw(title);
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
				charArray[i][j]->setCharType('p');
			}
			else if (j == 7)
			{
				switch (i)
				{
				case 0:
					charArray[i][j] = new Rook;
					charArray[i][j]->setCharType('r');
					break;
				case 1:
					charArray[i][j] = new Knight;
					charArray[i][j]->setCharType('k');
					break;
				case 2:
					charArray[i][j] = new Bishop;
					charArray[i][j]->setCharType('b');
					break;
				case 3:
					charArray[i][j] = new Queen;
					charArray[i][j]->setCharType('Q');
					break;
				case 4:
					charArray[i][j] = new King;
					charArray[i][j]->setCharType('K');
					break;
				case 5:
					charArray[i][j] = new Bishop;
					charArray[i][j]->setCharType('b');
					break;
				case 6:
					charArray[i][j] = new Knight;
					charArray[i][j]->setCharType('k');
					break;
				case 7:
					charArray[i][j] = new Rook;
					charArray[i][j]->setCharType('r');
					break;
				}
			}
			else
			{
				charArray[i][j] = new ChessChar;
			}
			charArray[i][j]->InitSprite();
			charArray[i][j]->SetPos(i * DEFAULT_SIZEf + 560.f, j * DEFAULT_SIZEf + 140.f);
			charArray[i][j]->setIndex(sf::Vector2i(i, j));
		}
	}

	charArray[0][7]->setSelected(true);
	selectedSq = charArray[0][7];
	tileArray[0][7].setOutlineThickness(-2);
	tileArray[0][7].setOutlineColor(sf::Color::Green);
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

void Board::BuildOptions(sf::RenderWindow& inputWindow)
{
	for (auto i : optionDots)
	{
		inputWindow.draw(i);
	}
}


void Board::SelectSquare(char movementDescision)
{
	int xCoord = selectedSq->getIndex().x;
	int yCoord = selectedSq->getIndex().y;

	if (movementDescision == 'W')
	{
		if (yCoord - 1 < 0)
		{
			return;
		}

		selectedSq->setSelected(false);
		selectedSq->setLockIn(false);

		tileArray[xCoord][yCoord].setOutlineThickness(0);

		charArray[xCoord][yCoord - 1]->setSelected(true);

		tileArray[xCoord][yCoord - 1].setOutlineThickness(-2);
		tileArray[xCoord][yCoord - 1].setOutlineColor(sf::Color::Green);

		selectedSq = charArray[xCoord][yCoord - 1];
	}
	else if (movementDescision == 'A')
	{
		if (xCoord - 1 < 0)
		{
			return;
		}

		selectedSq->setSelected(false);
		selectedSq->setLockIn(false);

		tileArray[xCoord][yCoord].setOutlineThickness(0);

		charArray[xCoord - 1][yCoord]->setSelected(true);

		tileArray[xCoord - 1][yCoord].setOutlineThickness(-2);
		tileArray[xCoord - 1][yCoord].setOutlineColor(sf::Color::Green);

		selectedSq = charArray[xCoord - 1][yCoord];
	}
	else if (movementDescision == 'S')
	{
		if (yCoord + 1 > 7)
		{
			return;
		}

		selectedSq->setSelected(false);
		selectedSq->setLockIn(false);

		tileArray[xCoord][yCoord].setOutlineThickness(0);

		charArray[xCoord ][yCoord + 1]->setSelected(true);

		tileArray[xCoord][yCoord + 1].setOutlineThickness(-2);
		tileArray[xCoord][yCoord + 1].setOutlineColor(sf::Color::Green);

		selectedSq = charArray[xCoord][yCoord + 1];
	}
	else if (movementDescision == 'D')
	{
		if (xCoord + 1 > 7)
		{
			return;
		}

		selectedSq->setSelected(false);
		selectedSq->setLockIn(false);

		tileArray[xCoord][yCoord].setOutlineThickness(0);

		charArray[xCoord + 1][yCoord]->setSelected(true);

		tileArray[xCoord + 1][yCoord].setOutlineThickness(-2);
		tileArray[xCoord + 1][yCoord].setOutlineColor(sf::Color::Green);

		selectedSq = charArray[xCoord + 1][yCoord];
	}

	//MOUSE SELECTION SQUARE USING MOUSE DO LATER
	/*
	sf::Vector2u gridPos((mousePos.x / unsigned_DEFAULT_SIZE) - 560, (mousePos.y / unsigned_DEFAULT_SIZE) - 140);
	std::cout << gridPos.x << " " << gridPos.y << std::endl;



	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (gridPos == static_cast<sf::Vector2u>(charArray[i][j]->GetSprite().getPosition()))
			{
				tileArray[i][j].setFillColor(sf::Color::Black);
				std::cout << charArray[i][j]->GetSprite().getPosition().x << " " << charArray[i][j]->GetSprite().getPosition().y << std::endl;
				std::cout << gridPos.x << " " << gridPos.y << std::endl;
			}
		}
	}

	*/	
}

void Board::EnterSquare()
{
	
	if (optionDots.size() > 0)
	{
		return;
	}

	delete enteredChar;

	enteredChar = new ChessChar;
	*enteredChar = *selectedSq;

	sf::CircleShape tempCirc;

	tempCirc.setFillColor(sf::Color(25, 46, 46, 155));
	tempCirc.setRadius(30.f);

	float dotXPos;
	float dotYPos;

	dotCounter = 0;

	int xCoord = selectedSq->getIndex().x;
	int yCoord = selectedSq->getIndex().y;

	tileArray[xCoord][yCoord].setOutlineColor(sf::Color::Blue);

	switch (selectedSq->getCharType())
	{
	case 'p':

		for (int i = 1; i <= 2; i++)
		{
			if (charArray[xCoord][yCoord - i]->getCharType() != 'E')
			{
				return;
			}

			dotXPos = tileArray[xCoord][yCoord - i].getPosition().x;
			dotYPos = tileArray[xCoord][yCoord - i].getPosition().y;
			charArray[xCoord][yCoord - i]->setTaggedOption(true);

			//The + 15.f is to put the dot in the middle
			tempCirc.setPosition(sf::Vector2f(dotXPos + 50.f - 30.f, dotYPos + 50.f - 30.f));
			
			optionDots.push_back(tempCirc);
			dotCounter++;
		}
		break;

	case 'r':
		//Pos y
		for (int i = 1; i <= 7; i++)
		{
			if (charArray[xCoord][yCoord + i]->getCharType() != 'E')
			{
				break;
			}

			dotXPos = tileArray[xCoord][yCoord + i].getPosition().x;
			dotYPos = tileArray[xCoord][yCoord + 1].getPosition().y;
			charArray[xCoord][yCoord + i]->setTaggedOption(true);

			tempCirc.setPosition(sf::Vector2f(dotXPos + 50.f - 30.f, dotYPos + 50.f - 30.f));

			optionDots.push_back(tempCirc);
			dotCounter++;
		}

		//Neg y
		for (int i = 1; i <= 7; i++)
		{
			std::cout << "Yo" << std::endl;
			if (charArray[xCoord][yCoord]->getCharType() != 'E')
			{
				break;
			}

			dotXPos = tileArray[xCoord][yCoord + i].getPosition().x;
			dotYPos = tileArray[xCoord][yCoord + i].getPosition().y;
			charArray[xCoord][yCoord + i]->setTaggedOption(true);

			tempCirc.setPosition(sf::Vector2f(dotXPos + 20.f, dotYPos + 20.f));

			optionDots.push_back(tempCirc);
			dotCounter++;
		}

		break;
	}
}

void Board::MakeMove()
{
	if (selectedSq->getTaggedOption())
	{
		sf::Vector2i enteredCharIndex = enteredChar->getIndex();
		sf::Vector2i selectedCharIndex = selectedSq->getIndex();

		charArray[enteredCharIndex.x][enteredCharIndex.y] = new ChessChar;
		charArray[enteredCharIndex.x][enteredCharIndex.y]->setCharType('E');

		charArray[enteredCharIndex.x][enteredCharIndex.y]->InitSprite();
		charArray[enteredCharIndex.x][enteredCharIndex.y]->SetPos(enteredCharIndex.x * DEFAULT_SIZEf + 560.f, enteredCharIndex.y * DEFAULT_SIZEf + 140.f);
		charArray[enteredCharIndex.x][enteredCharIndex.y]->setIndex(sf::Vector2i(enteredCharIndex.x, enteredCharIndex.y));

		charArray[enteredCharIndex.x][enteredCharIndex.y]->setLockIn(false);

		switch (enteredChar->getCharType())
		{
			{
		case 'p':

			//delete charArray[selectedCharIndex.x][selectedCharIndex.y];

			charArray[selectedCharIndex.x][selectedCharIndex.y] = new Pawn;
			charArray[selectedCharIndex.x][selectedCharIndex.y]->setCharType('p');

			break;

		case 'r':

			//delete charArray[selectedCharIndex.x][selectedCharIndex.y];

			charArray[selectedCharIndex.x][selectedCharIndex.y] = new Rook;
			charArray[selectedCharIndex.x][selectedCharIndex.y]->setCharType('r');

			break;
			}
		}

		charArray[selectedCharIndex.x][selectedCharIndex.y]->InitSprite();
		charArray[selectedCharIndex.x][selectedCharIndex.y]->SetPos(selectedCharIndex.x * DEFAULT_SIZEf + 560.f, selectedCharIndex.y * DEFAULT_SIZEf + 140.f);
		charArray[selectedCharIndex.x][selectedCharIndex.y]->setIndex(sf::Vector2i(selectedCharIndex.x, selectedCharIndex.y));



	}	

	for (int i = 0; i < dotCounter; i++)
	{
		optionDots.pop_back();
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			charArray[i][j]->setTaggedOption(false);
		}
	}
}

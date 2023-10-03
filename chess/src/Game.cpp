#include "Game.h"

void Game::InitBoard()
{
	chessBoard.InitBoard();
}

void Game::BuildBoard(sf::RenderWindow& inputWindow)
{
	chessBoard.BuildBoard(inputWindow);
}

void Game::InitText()
{
	font.loadFromFile("OpenSans-Bold.ttf");

	title.setCharacterSize(30);
	title.setFillColor(sf::Color::White);
	title.setPosition(20.f, 20.f);
	title.setFont(font);
	title.setString("CHESS");
}

void Game::BuildText(sf::RenderWindow& inputWindow)
{
	inputWindow.draw(title);
}
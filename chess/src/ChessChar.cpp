#include "ChessChar.h"

void ChessChar::InitSprite()
{
	charTex.loadFromFile("./Empty.png");

	charSprite.setTexture(charTex);
}

void ChessChar::SetPos(float inputVal1, float inputVal2)
{
	charSprite.setPosition(sf::Vector2f(inputVal1, inputVal2));
}

void ChessChar::setColor(bool inputBool)
{
	color = inputBool;
}

void ChessChar::setSelected(bool inputBool)
{
	selected = inputBool;
}

void ChessChar::setIndex(sf::Vector2i inputIndex)
{
	index = inputIndex;
}

void ChessChar::isOpenSquare(bool inputBool)
{
	isMovable = inputBool;
}

sf::Vector2i ChessChar::getIndex()
{
	return index;
}

sf::Sprite ChessChar::GetSprite()
{
	return charSprite;
}

bool ChessChar::getSelected()
{
	return selected;
}
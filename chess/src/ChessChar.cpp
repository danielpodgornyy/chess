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

void ChessChar::setLockIn(bool inputBool)
{
	lockIn = inputBool;
}

bool ChessChar::getTaggedOption()
{
	return taggedOption;
}

void ChessChar::setTaggedOption(bool inputBool)
{
	taggedOption = inputBool;
}


void ChessChar::setCharType(char inputChar)
{
	charType = inputChar;
}

char ChessChar::getCharType()
{
	return charType;
}

bool ChessChar::getLockIn()
{
	return lockIn;
}

void ChessChar::setIsOpenSquare(bool inputBool)
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
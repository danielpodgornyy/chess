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

void ChessChar::isOpenSquare(bool inputBool)
{
	isMovable = inputBool;
}

sf::Sprite ChessChar::GetSprite()
{
	return charSprite;
}
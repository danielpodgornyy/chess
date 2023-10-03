#include "Knight.h"

void Knight::InitSprite()
{
	charTex.loadFromFile("./KnightTex.png");

	charSprite.setTexture(charTex);
}
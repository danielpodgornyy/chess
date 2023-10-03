#include "King.h"

void King::InitSprite()
{
	charTex.loadFromFile("./KingTex.png");

	charSprite.setTexture(charTex);
}
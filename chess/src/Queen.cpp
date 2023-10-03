#include "Queen.h"

void Queen::InitSprite()
{
	charTex.loadFromFile("./QueenTex.png");

	charSprite.setTexture(charTex);
}
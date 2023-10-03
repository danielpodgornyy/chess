#include "Bishop.h"

void Bishop::InitSprite()
{
	charTex.loadFromFile("./BishopTex.png");

	charSprite.setTexture(charTex);
}
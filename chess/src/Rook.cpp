#include "Rook.h"

void Rook::InitSprite()
{
	charTex.loadFromFile("./RookTex.png");

	charSprite.setTexture(charTex);
}
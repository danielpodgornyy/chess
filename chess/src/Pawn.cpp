#include "Pawn.h"

void Pawn::InitSprite()
{
	charTex.loadFromFile("./PawnTex.png");

	charSprite.setTexture(charTex);
}
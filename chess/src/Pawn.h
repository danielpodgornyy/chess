#include "ChessChar.h"

class Pawn : public ChessChar
{
	public:
		void InitSprite() override;

	private:
		char charType = 'p';
};
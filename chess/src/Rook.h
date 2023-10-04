#include "ChessChar.h"

class Rook : public ChessChar
{
public:
	void InitSprite() override;

private:
	char charType = 'r';
};

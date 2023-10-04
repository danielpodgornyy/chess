#include "ChessChar.h"

class Bishop : public ChessChar
{
public:
	void InitSprite() override;

private:
	char charType = 'b';
};
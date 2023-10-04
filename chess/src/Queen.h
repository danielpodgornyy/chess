#include "ChessChar.h"

class Queen : public ChessChar
{
public:
	void InitSprite() override;

private:
	char charType = 'Q';
};

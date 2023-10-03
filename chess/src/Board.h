#include "ChessChar.h"


class Board //: public sf::Drawable, public sf::Transformable
{
	public:
		void InitBoard();
		void BuildBoard(sf::RenderWindow& inputWindow);

	private:
		sf::RectangleShape tileArray[8][8];
		ChessChar* charArray[8][8];
		const float DEFAULT_SIZEf = 100.f;
		unsigned unsigned_DEFAULT_SIZE = static_cast<unsigned>(DEFAULT_SIZEf);
};

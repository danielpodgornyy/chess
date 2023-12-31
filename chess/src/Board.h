#include "ChessChar.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

class Board //: public sf::Drawable, public sf::Transformable
{
	public:
		void InitBoard();
		void BuildBoard(sf::RenderWindow& inputWindow);

		void InitText();
		void BuildText(sf::RenderWindow& inputWindow);

		void InitCharArray();

		void BuildCharArray(sf::RenderWindow& inputWindow);

		void BuildOptions(sf::RenderWindow& inputWindow);

		void Decide();
		void SelectSquare(char movementDescision);
		void EnterSquare();
		void MakeMove();
	private:
		sf::Text title;
		sf::Font font;

		sf::RectangleShape tileArray[8][8];
		ChessChar* charArray[8][8];
		ChessChar* selectedSq;
		ChessChar* prevSelectedSq;
		ChessChar* enteredChar;

		bool squareLockedIn;
		std::list<sf::CircleShape> optionDots;
		int dotCounter;
		const float DEFAULT_SIZEf = 100.f;
		unsigned unsigned_DEFAULT_SIZE = static_cast<unsigned>(DEFAULT_SIZEf);
};
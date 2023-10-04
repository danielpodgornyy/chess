#include "Board.h"

class Game
{
	public:
		void InitBoard();
		void BuildBoard(sf::RenderWindow& inputWindow);

		void InitCharArray();
		void BuildCharArray(sf::RenderWindow& inputWindow);

		void InitText();
		void BuildText(sf::RenderWindow& inputWindow);

		void SelectSquare(char movementDescision);
		void EnterSquare();
	private:
		Board chessBoard;
		sf::Text title;
		sf::Font font;
};


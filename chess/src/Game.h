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

		void SelectSquare(sf::Vector2i mousePos);
	private:
		Board chessBoard;
		sf::Text title;
		sf::Font font;
};


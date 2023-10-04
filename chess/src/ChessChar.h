#ifndef CHESSCHAR
#define CHESSCHAR

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "iostream"

class ChessChar
{
	public:
		virtual void InitSprite();
		void SetPos(float inputVal1, float inputVal2);
		void setColor(bool inputBool);
		void setSelected(bool inputBool);
		void isOpenSquare(bool inputBool);
		void setIndex(sf::Vector2i inputIndex);
		sf::Vector2i getIndex();
		bool getSelected();
		sf::Sprite GetSprite();
	protected:
		bool color; //1 for white, 0 for black
		bool isMovable;
		bool selected = false;
		sf::Vector2i index;
		sf::Sprite charSprite;
		sf::Texture charTex;
};

#endif
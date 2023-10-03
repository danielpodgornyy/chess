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
		void isOpenSquare(bool inputBool);
		sf::Sprite GetSprite();
	protected:
		bool color; //1 for white, 0 for black
		bool isMovable;
		sf::Sprite charSprite;
		sf::Texture charTex;
};

#endif
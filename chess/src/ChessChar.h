#ifndef CHESSCHAR
#define CHESSCHAR

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include <list>

class ChessChar
{
	public:
		virtual void InitSprite();
		void SetPos(float inputVal1, float inputVal2);
		void setColor(bool inputBool);
		void setIsOpenSquare(bool inputBool);
		void setIndex(sf::Vector2i inputIndex);
		void setLockIn(bool inputBool);
		bool getCharPresent();
		void setCharPresent(bool inputChar);
		bool getTaggedOption();
		void setTaggedOption(bool inputBool);
		void setCharType(char inputChar);
		char getCharType();
		bool getLockIn();
		sf::Vector2i getIndex();
		sf::Sprite GetSprite();
	protected:
		bool color; //1 for white, 0 for black
		bool isMovable;
		bool taggedOption = false;//tagged with dots
		bool charPresent = false;//true if a character is present in the square
		bool lockIn = false; //Ready to move
		char charType = 'E';
		sf::Vector2i index;
		sf::Sprite charSprite;
		sf::Texture charTex;
};

#endif
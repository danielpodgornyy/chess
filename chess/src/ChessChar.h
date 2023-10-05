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
		void setSelected(bool inputBool);
		void setIsOpenSquare(bool inputBool);
		void setIndex(sf::Vector2i inputIndex);
		void setLockIn(bool inputBool);
		bool getTaggedOption();
		void setTaggedOption(bool inputBool);
		void setCharType(char inputChar);
		char getCharType();
		bool getLockIn();
		sf::Vector2i getIndex();
		bool getSelected();
		sf::Sprite GetSprite();
	protected:
		bool color; //1 for white, 0 for black
		bool isMovable;
		bool taggedOption = false;
		bool selected = false; //Move through board;
		bool lockIn = false; //Ready to move
		char charType = 'E';
		sf::Vector2i index;
		sf::Sprite charSprite;
		sf::Texture charTex;
};

#endif
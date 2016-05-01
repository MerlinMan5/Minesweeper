#pragma once
#include <Windows.H>
#include <FL/Fl_Window.H>
#include "Square.h"
#include <vector>
#include <FL/Fl.h>
#include <FL/Fl_JPEG_Image.h>
#include <FL/Fl_Box.H>
#include <string>
#include <vector>

class Square;

class Board : public Fl_Window
{
	std::vector <std::string> imageNames;
	Square* mine;
	int minesFlagged = 0;
	Square* normal;
public:

	bool gameover = false;
	void squarePressed(Fl_Widget * widget);
	int handle_key(int e, int key, bool shift);
	int handle(int e);
	int debugIterator;
	void countMines(std::vector < std::vector<Square*> > &board, int x, int  y);
	int checkSurrounding(std::vector<std::vector<Square*>>& board, int x, int y);
	int totalMines(std::vector<std::vector<Square*>>& gameboard);
	void checkWin(std::vector<std::vector<Square*>>& gameboard);

	Board(int width, int height, int x, int y, bool debug, std::vector<std::string> imageNames);
	std::vector < std::vector <Square *> > gameboard;

};
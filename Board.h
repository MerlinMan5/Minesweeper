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

class Board : public Fl_Window
{
	std::vector <std::string> imageNames;

	Square* mine;
	Square* normal;
public:
	void squarePressed(Fl_Widget * widget);
	int handle_key(int e, int key, bool shift);
	int handle(int e);
	int debugIterator;
	//int countMines(std::vector < std::vector<Square*> > &board, const int y, const int  x);

	Board(int width, int height, int x, int y, bool debug, std::vector<std::string> imageNames);
	std::vector < std::vector <Square *> > gameboard;


	/*vector < vector<Square*> > gameboard;
	vector <Square *> rowVec;*/

	//int handle(int e);

};
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
	bool debug;
	std::vector<std::vector<Square*>> gameboard;
	int wide;
	int tall;

public:

	void squarePressed(Fl_Widget * widget);
	void modeChanger(Fl_Widget* widget, Board* board);

	Board(int width,
		int height,
		int x,
		int y,bool debugger,
		std::vector<std::string> imageNames);

	int handle_key(int e, int key, bool shift);
	bool getDebug();
	void setDebug(bool x);

	int handle(int e);

};
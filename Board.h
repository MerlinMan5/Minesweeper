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

public:

	void squarePressed(Fl_Widget * widget);
	bool squarePressed(Board* board, void* ptr);

	Board(int width,
		int height,
		int x,
		int y,
		std::vector<std::string> imageNames);

	int handle_key(int e, int key, bool shift);
	bool getDebug();
	void setDebug(bool x);

	int handle(int e);

};
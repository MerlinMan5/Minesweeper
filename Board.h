#pragma once
#include <Windows.H>
#include <FL/Fl_Window.H>
#include "Square.h"
#include "Cell.h"
#include <vector>
#include <FL/Fl.h>
#include <FL/Fl_JPEG_Image.h>
#include <FL/Fl_Box.H>

class Board : public Fl_Window
{
	Square* square;
	Cell* cell;

public:
	
	void minePressed(Fl_Widget * widget);

	Board(int width, int height, int x, int y, bool debug);
	void minePressed(Fl_Widget * w);
};
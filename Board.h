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
	Square* square2;
	Cell* cell;
	int handle_key(int event, int key, int e);

public:
	
	Board(int width, int height, int x, int y);
	int handle(int event);
	void buttonCallback(Fl_Widget * w, void * data);
};
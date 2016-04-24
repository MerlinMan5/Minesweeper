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
	
	Board(int, int);
	void buttonCallback(Fl_Widget * w, void * data);
};
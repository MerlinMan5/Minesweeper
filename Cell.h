#pragma once
#include <Windows.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl.h>
#include <FL/Fl_JPEG_Image.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>

//Cell is effectivly the sae thing as square execpt it is type Box not button
class Cell : public Fl_Box
{
	int clickCount;

public:

	Cell(int x, int y, int width, int height, char *L);

	int handle(int event);

};
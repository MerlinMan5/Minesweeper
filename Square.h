#pragma once
#include <Windows.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl.h>
#include <FL/Fl_JPEG_Image.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>

class Square : public Fl_Button
{
	int clickCount;

public:

	Square(int x, int y, int width, int height, char *L);

	int handle(int event);

};
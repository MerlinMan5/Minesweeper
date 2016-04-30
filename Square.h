#pragma once
#include <Windows.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.h>
#include <string>

class Square : public Fl_Button
{
	Fl_JPEG_Image* imageLabel;
	std::string label;
	std::string tag;
	std::string rightClick;

public:

	int rightClickIterator = 0;
	Square(unsigned int x, unsigned int y, unsigned int width, unsigned int height, const char *L,
		std::string imageFilename, std::string tag, std::string rightClick);

	void setRightClick(char* l);
	std::string getLabel() const;
	std::string getTag() const;
	std::string getRightClick() const;

	void setImage(std::string x);
	int handle(int e);


};
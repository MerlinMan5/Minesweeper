#pragma once
#include <Windows.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.h>
#include <string>

class Board;

class Square : public Fl_Button
{
	Fl_JPEG_Image* imageLabel;
	std::string label;
	std::string tag;
	std::string rightClick;

public:

	Square(unsigned int x, unsigned int y, unsigned int width, unsigned int height, const char *L,
		std::string imageFilename, std::string tag, std::string rightClick, bool isCovered, Board* b);

	Board* boardpointer;
	int rightClickIterator = 0;
	bool isCovered;
	bool flagOn = false;

	bool Square::getIsCovered();
	void Square::setIsCovered(bool trip);

	std::string getLabel() const;
	void setLabel(std::string swag);

	std::string getRightClick() const;
	void setRightClick(char* l);

	std::string getTag() const;
	void setTag(std::string n);

	void setImage(std::string x);
	int handle(int e);
};
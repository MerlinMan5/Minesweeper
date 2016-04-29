#pragma once
#include <Windows.H>
#include <FL/Fl.H>
#pragma once
#include <FL/Fl_Button.H>
#include <FL/Fl.h>
#include <FL/Fl_JPEG_Image.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <string>

class Square : public Fl_Button
{
	int clickCount;
	char* label;
	Fl_JPEG_Image* imagelabel;
	std::string tag;
	bool flag;
public:

	Square(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char* L,
		std::string imageFilename, std::string tag);

	bool getFlag();
	void setLabel(char* l);
	char* getLabel() const;
	std::string getTag() const;
	void setImage(std::string x);
	int handle(int e);


}; 

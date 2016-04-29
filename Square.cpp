#include "Square.h"
#include "Board.h"
#include <iostream>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>


using namespace std;

Square::Square(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char* L, string imageFilename, string tag) :
	Fl_Button(x, y, width, height, L), clickCount(0), imagelabel(nullptr), tag(tag), flag(false) {

	setImage(imageFilename);
}
void Square::setLabel(char* l) {
	label = l;
}
char* Square::getLabel() const {
	return label;
}

bool Square::getFlag() {
	return flag;
}

string Square::getTag() const {
	return tag;
}

void Square::setImage(string filename) {
	delete imagelabel;
	imagelabel = new Fl_JPEG_Image(filename.c_str());
	imagelabel->copy(16, 16);
	this->image(imagelabel);
	this->align(FL_ALIGN_CENTER);
}

int Square::handle(int event)
{
	switch (event) {
	case FL_RELEASE:
		switch (Fl::event_button())
		{
		case FL_LEFT_MOUSE:
			clickCount++;
			this->flag = false;
			this->do_callback();
			return 1;
		case FL_RIGHT_MOUSE:
			this->flag = true;
			this->do_callback();
			return 1;
		}
	default:
		return Fl_Widget::handle(event);
	}
}
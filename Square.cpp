#include "Square.h"
#include "Board.h"
#include <iostream>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>


using namespace std;

Square::Square(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char* L, string imageFilename, string tag, bool flag) :
	Fl_Button(x, y, width, height, L), clickCount(0), imagelabel(nullptr), tag(tag), fcheck(fcheck), flag(flag) {

	setImage(imageFilename);
	align(-1);
}
void Square::setLabel(char* l) {
	label = l;
}
char* Square::getLabel() const {
	return label;
}

void Square::setFcheck(bool x) {
	fcheck = x;
}

bool Square::getFcheck() {
	return fcheck;
}

bool Square::getFlag() {
	return flag;
}
void Square::setFlag(bool x) {
	flag = x;
}

string Square::getTag() const {
	return tag;
}

void Square::setImage(string filename) {
	delete imagelabel;
	imagelabel = new Fl_JPEG_Image(filename.c_str());
	image(imagelabel);	
	
}

int Square::handle(int event)
{
	switch (event) {
	case FL_RELEASE:
		switch (Fl::event_button())
		{
		case FL_LEFT_MOUSE:
			this->setFcheck(false);
			clickCount++;
			this->do_callback();
			return 1;
		case FL_RIGHT_MOUSE:
			this->setFcheck(true);
			this->do_callback();
			return 1;
		}
	default:
		return Fl_Widget::handle(event);
	}
}
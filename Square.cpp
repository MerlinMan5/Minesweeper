#include "Square.h"
#include "Board.h"
#include <iostream>
#include <vector>
using namespace std;
bool flagOn = false;

Square::Square(unsigned int x, unsigned int y, unsigned int width, unsigned int height, const char * L, string imageFilename, string tag, string rightClick) :
	Fl_Button(x, y, width, height, L), label(L), imageLabel(nullptr), tag(tag), rightClick(rightClick)
{
	align(-1);
	setImage(imageFilename);
}

string Square::getLabel() const
{
	return label;
}

string Square::getRightClick() const
{
	return rightClick;
}

void Square::setRightClick(char* l)
{
	rightClick = l;
}

string Square::getTag() const
{
	return tag;
}

void Square::setImage(string filename)
{
	delete imageLabel;
	imageLabel = new Fl_JPEG_Image(filename.c_str());
	imageLabel->copy(16, 16);
	image(imageLabel);
	this->resize(this->x(), this->y(), 16, 16);
}

int Square::handle(int event)
{
	switch (event)
	{
	case FL_RELEASE:
		switch (Fl::event_button())
		{
		case FL_LEFT_MOUSE:
			this->do_callback();
			return 0;
		case FL_RIGHT_MOUSE:
			rightClickIterator++;

			if ((rightClickIterator % 3) == 0)
			{
				cout << "reseting" << endl;
				rightClickIterator = 0;
			}
			if (rightClickIterator == 1)
			{
				this->setImage("images/flaggedMine.jpg");
				this->setRightClick("F");
				redraw();
			}
			else if (rightClickIterator == 2)
			{
				this->setImage("images/question.jpg");
				this->setRightClick("?");
				redraw();
			}
			else
			{
				this->setImage("images/coveredTile.jpg");
				this->setRightClick(" ");
				do_callback();
				redraw();
			}
			return 0;
		}
	default:
		return Fl_Widget::handle(event);
	}
}
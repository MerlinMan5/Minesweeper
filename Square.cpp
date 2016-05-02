#include <Windows.H>
#include "Square.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <FL/Fl_Output.H>

using namespace std;

Square::Square(unsigned int x, unsigned int y, unsigned int width, unsigned int height, const char * L, string imageFilename, string tag, string rightClick, bool isCovered, Board* b) :
	Fl_Button(x, y, width, height, L), label(L), imageLabel(nullptr), tag(tag), rightClick(rightClick), isCovered(isCovered), boardpointer(b)
{
	align(-1);
	setImage(imageFilename);
}

string Square::getLabel() const
{
	return label;
}

void Square::setLabel(string swag)
{
	label = swag;
}

void Square::setTag(string n)
{
	tag = n;
}

string Square::getRightClick() const
{
	return rightClick;
}

void Square::setRightClick(char* l)
{
	rightClick = l;
}

void Square::setIsCovered(bool trip)
{
	isCovered = trip;
}

bool Square::getIsCovered()
{
	return isCovered;
}

string Square::getTag() const
{
	return tag;
}

//Takes square and puts an image on it
void Square::setImage(string filename)
{
	delete imageLabel;
	imageLabel = new Fl_JPEG_Image(filename.c_str());
	imageLabel->copy(16, 16);
	image(imageLabel);
	this->resize(this->x(), this->y(), 16, 16);
}

//Controls respone to left and right clicks
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

			if (boardpointer->gameover == false)
			{
				if (boardpointer->gameboard.at(this->x() / 16).at((this->y() / 16) - 1)->getIsCovered() == true)
				{
					if ((rightClickIterator % 3) == 0)
					{
						rightClickIterator = 0;
					}
					if (rightClickIterator == 1)
					{
						boardpointer->totalFlagged++;
						this->setImage("images/flaggedMine.jpg");
						this->setRightClick("F");
						boardpointer->checkWin(boardpointer->gameboard);
						redraw();
					}
					else if (rightClickIterator == 2)
					{
						boardpointer->totalFlagged--;
						this->setImage("images/question.jpg");
						this->setRightClick("?");
						redraw();
					}
					else
					{
						this->setImage("images/coveredTile.jpg");
						this->setRightClick(" ");
						redraw();
					}
				}
			}
			return 0;
		}
	default:
		return 0;
	}
}
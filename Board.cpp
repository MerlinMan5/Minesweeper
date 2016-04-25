#include "Board.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
void buttonCallback(Fl_Widget* widget, void* boardPtr) {
	cout << "callback called" << endl;
	Board* board = static_cast<Board*>(boardPtr);
	board->minePressed(widget);
}

void Board::minePressed(Fl_Widget* widget) {
	Square* square = static_cast<Square*>(widget);
	if (square->label() == "M") {
		Fl_JPEG_Image *pic = new Fl_JPEG_Image();
		square->image(pic);
	}
	else {
		//FIXME change to number// 
	}
	Fl_Widget::redraw();

}

Board::Board(int width = 200, int height = 300, int Squaresx = 17, int Squaresy = 12, bool debug = false) :
	Fl_Window(width, height)
{
	srand(time(NULL));//Sets random to be even more random!
	color(FL_BLACK); //board

	if (debug)
	{
		for (int y = 0; y < Squaresy; y++)
		{
			for (int x = 0; x < Squaresx; x++)
			{
				if ((rand() % 5) == 1)
				{
					square = new Square((16 * x), (16 * y), 16, 16, "M");
				}
				else
				{
					square = new Square((16 * x), (16 * y), 16, 16, "");
				}
			}
		}
	}
	else
	{
		for (int y = 0; y < Squaresy; y++)
		{
			for (int x = 0; x < Squaresx; x++)
			{
				if ((rand() % 5) == 1)
				{
					square = new Square((16 * x), (16 * y), 16, 16, " ");
				}
				else
				{
					square = new Square((16 * x), (16 * y), 16, 16, "");
				}
			}
		}
	}


	//*********************************


	/*string file2 = "images/mine.jpg";
	Fl_JPEG_Image img(file2.c_str());
	if (img.w() == 0 || img.h() == 0 || img.d() == 0)
	{
		cerr << "Error loading image." << endl;
		system("pause");
	}
	else
	{
		cout << "good image" << endl;
	}


	for (int y = 0; y < Squaresy; y++)
	{
		for (int x = 0; x < Squaresx; x++)
		{
			if ((rand() % 5) == 1)
			{
			cell = new Cell((16 * x), (16 * y), 16, 16, "M");
				this->image(img);

			}
			else
			{
			cell = new Cell((16 * x), (16 * y), 16, 16, "");
			}
		}
	}
*/



/*
box->labelfont(FL_BOLD);
box->labelcolor(FL_BLUE);
box->labelsize(12);
*/

	this->end();
}
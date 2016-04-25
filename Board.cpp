#include "Board.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
bool debug = true;
int Squaresx;
int Squaresy;

Board::Board(int width = 200, int height = 300, int Squaresx = 17, int Squaresy = 12) :
	Fl_Window(width, height)
{
	srand(time(NULL));//Sets random to be even more random!

	this->color(FL_BLACK); //board

	//for (int y = 1; y < 18; y++)
	//{
	//	for (int x = 0; x < 12; x++)
	//	{
	//		square = new Square(5 + (16 * x), (16 * y), 16, 16, "");
	//	}
	//}
	if (debug)
	{
		for (int y = 0; y < Squaresy; y++)
		{
			for (int x = 0; x < Squaresx; x++)
			{
				if ((rand() % 4) == 1)
				{
					square2 = new Square((16 * x), (16 * y), 16, 16, "M");
				}
				else
				{
					square = new Square((16 * x), (16 * y), 16, 16, "");
				}
			}
		}
	}
	else if (!debug)
	{
		for (int y = 0; y < Squaresy; y++)
		{
			for (int x = 0; x < Squaresx; x++)
			{
				if ((rand() % 4) == 1)
				{
					square2 = new Square((16 * x), (16 * y), 16, 16, " ");
				}
				else
				{
					square = new Square((16 * x), (16 * y), 16, 16, "");
				}
			}
		}
	}


	//*********************************


	/*string file2 = "images/emptyUncoveredTile.jpg";
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

	for (int y = 1; y < 18; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			cell = new Cell(5 + (16 * x), (16 * y), 16, 16, "");
		}
	}*/

	/*
	box->labelfont(FL_BOLD);
	box->labelcolor(FL_BLUE);
	box->labelsize(12);
	*/

	this->end();
}

int Board::handle_key(int event, int key, int e) {
	//switch (e) {
	//case FL_Shift_L:
		switch (key) {
		case 'd' :
			square2->clear();
			/*if (debug) {
				debug = false;
				for (int y = 0; y < Squaresy; y++)
				{
					for (int x = 0; x < Squaresx; x++)
					{
						if ((rand() % 4) == 1)
						{
							square2 = new Square((16 * x), (16 * y), 16, 16, " ");
						}
						else
						{
							square = new Square((16 * x), (16 * y), 16, 16, "");
						}
					}
				}
			}
			else if (!debug) {
				debug = true;
				for (int y = 0; y < Squaresy; y++)
				{
					for (int x = 0; x < Squaresx; x++)
					{
						if ((rand() % 4) == 1)
						{
							square2 = new Square((16 * x), (16 * y), 16, 16, "M");
						}
						else
						{
							square = new Square((16 * x), (16 * y), 16, 16, "");
						}
					}
				}
			}*/
			if (square2->label() == "M")
			{
				square2->label(" ");
				redraw();
			}
			else if (square2->label() == " ")
			{
				square2->label("M");
				redraw();
			}
			cout << "YES" << endl;
			//cout << debug << endl;
			redraw();
			return 1;
		default:
			cout << "NO" << endl;
			return 1;
		}
		//return 1;
	}
//}

int Board::handle(int event)
{
	switch (event) {
	case FL_KEYBOARD:
		//return handle_key(event, Fl::event_state(FL_Shift_L));
		return handle_key(event, Fl::event_key(), Fl::event_key());
	case FL_FOCUS:
		label("Gained focus");
		return 1;
	case FL_UNFOCUS:
		label("Lost focus");
		damage(1);
		return 1;
	default:
		return Fl_Window::handle(event);
	};
}
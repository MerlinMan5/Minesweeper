#include "Board.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

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

	for (int y = 1; y < Squaresy; y++)
	{
		for (int x = 0; x < Squaresx; x++)
		{
			if ((rand() % 4) == 1)
			{
				square = new Square(5 + (16 * x), (16 * y), 16, 16, "M");
			}
			else
			{
				square = new Square(5 + (16 * x), (16 * y), 16, 16, "");
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
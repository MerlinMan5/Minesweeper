#include "Cell.h"
#include "Board.h"
#include <iostream>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>

using namespace std;

//Cell is effectivly the sae thing as square execpt it is type Box not button
Cell::Cell(int x, int y, int width, int height, char *L = 0) :
	Fl_Box(x, y, width, height, L), clickCount(0)
{
}

int Cell::handle(int event)
{
	switch (event)
	{
	case FL_RELEASE:
		if (true)
		{
			string file2 = "images/emptyUncoveredTile.jpg";
			Fl_JPEG_Image img(file2.c_str());

			if (img.w() == 0 || img.h() == 0 || img.d() == 0)
			{
				cerr << "Error loading image." << endl;
				system("pause");
				return 1;
			}

			cout << "Box " << this->label() << ": " << clickCount << endl;
			//this->image(img);
			//this->color(FL_GREEN);
			clickCount++;
			redraw();
		}
		return 1;
	default:
		return Fl_Widget::handle(event);
	}
}
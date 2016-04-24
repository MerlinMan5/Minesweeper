#include "Square.h"
#include "Board.h"
#include <iostream>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>

using namespace std;

//Button
Square::Square(int x, int y, int width, int height, char *L = 0) :
	Fl_Button(x, y, width, height, L), clickCount(0)
{

}


void Square::buttonCallback(Fl_Widget *w, void *data)
{
	cout << "Callback called" << endl;
	/*square* c = static_cast<square*>(data);
	this->image(img);
	c->redraw();*/
}


int Square::handle(int event)
{
	switch (event)
	{

	case FL_RELEASE:
		switch (Fl::event_button())
		{
		case FL_LEFT_MOUSE:
			if (this->label() == "M")
			{
				cout << "clicked mine" << endl;
			}
			else
			{
				this->color(FL_GRAY_RAMP);
				clickCount++;
				cout << "Button" << this->label() << ": " << clickCount << endl;
				redraw();
			}
			do_callback(); //Not doing the callback!
			return 1;
		case FL_RIGHT_MOUSE:
			this->color(FL_RED);
			do_callback();
			redraw();
			return 1;
		}
	default:
		return Fl_Widget::handle(event);
	}
}
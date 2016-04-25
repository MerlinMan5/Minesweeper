#include "Square.h"
#include "Board.h"
#include <iostream>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>

using namespace std;

bool flagOn = true;
//Button
Square::Square(int x, int y, int width, int height, char *L = 0) :
	Fl_Button(x, y, width, height, L), clickCount(0)
{

}


//void Square::buttonCallback(Fl_Widget *w, void *data)
//{
//	cout << "Callback called" << endl;
//	/*square* c = static_cast<square*>(data);
//	this->image(img);
//	c->redraw();*/
//}


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
				//label() = "M";
				this->do_callback();
				cout << "YOU LOSE!!" << endl;
				//Fl_Window *window = new Fl_Window(200, 300);
				//Fl_Box *box = new Fl_Box(300, 300, 200, 200, "YOU LOSE!!");
				//redraw();
				Sleep(500);
				exit(0);
			}
			else if (this->label() == " ")
			{
				//label() = "M";
				cout << "YOU LOSE!!" << endl;
				//Fl_Window *window = new Fl_Window(200, 300);
				//Fl_Box *box = new Fl_Box(300, 300, 200, 200, "YOU LOSE!!");
				redraw();
				Sleep(500);
				exit(0);
			}
			else
			{
				this->color(FL_BLACK);
				clickCount++;
				cout << "Button" << this->label() << ": " << clickCount << endl;
				redraw();
			}
			do_callback(); //Not doing the callback!
			return 1;
		case FL_RIGHT_MOUSE:

			if (flagOn)
			{
				this->color(FL_GRAY);
				do_callback();
				redraw();
				flagOn = false;
			}
			else
			{
				this->color(FL_RED);
				do_callback();
				redraw();
				flagOn = true;
			}
			return 1;
		}
	default:
		return Fl_Widget::handle(event);
	}
}
#include "Board.h"
#include "Square.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;
bool replay;
string input;

void buttonCallback(Fl_Widget* widget, void* boardPtr) {
	cout << "callback called" << endl;
	Board* board = static_cast<Board*>(boardPtr);
	board->squarePressed(widget);
}
bool Board::squarePressed(Board* board, void* ptr) {
	cout << "mode changer" << endl;
	bool mode = board->getDebug();
	Square* square = static_cast<Square*>(ptr);

	if (square->getTag() == "M")
	{
		if (mode == false)
		{
			cout << "howdy" << endl;
			square->setLabel(" ");
			mode = true;
			mine->redraw();
		}
		else if (mode == true)
		{
			cout << "howdy2" << endl;
			square->setLabel("M");
			mode = false;
			square->redraw();
		}
	}
	board->setDebug(mode);
	cout << "debug: " << board->getDebug() << endl;
	return board->getDebug();
}

void Board::squarePressed(Fl_Widget* widget) {

	Square* square = static_cast<Square*>(widget);
	bool flag = square->getFlag();

	if (flag == true) {
		if (square->color() == FL_RED){
			square->color(FL_GRAY);
			square->redraw();
		}
		else if (square->color() == FL_GRAY) {
			square->color(FL_RED);
			square->redraw();
		}
	}
	else if (flag == false)
	{
		if (square->getTag() == "M") {
			square->setImage("squareimages/mine.jpg");
			square->redraw();
			cout << "YOU LOSE" << endl;
		}
		else if (square->getTag() == "N") {
			cout << "non-mine" << endl;
			square->setImage("squareimages/emptyUncoveredTile.jpg");
			square->redraw();
			//FIXME function to put in number and check squares around
		}
	}
}

Board::Board(int width, int height, int Squaresx, int Squaresy, vector<string> imageNames) : debug(debug),
	Fl_Window(width, height)
{
	srand(time(NULL)); //Sets random to be even more random!
	color(FL_BLACK); //board
	vector < vector<Square*> > swag;
	vector <Square *> rowVec;
	unsigned int x;
	unsigned int y;
	void* view = static_cast<void*>(this);
	bool debug = getDebug();

	if (debug)
	{
		for (y = 0; y < Squaresy; y++)
		{
			for (x = 0; x < Squaresx; x++)
			{
				if ((rand() % 5) == 1)
				{
					mine = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "M");
					mine->callback(buttonCallback, view);
					rowVec.push_back(mine);
				}
				else
				{
					normal = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "N");
					normal->callback(buttonCallback, view);
					rowVec.push_back(normal);
				}
			}
			swag.push_back(rowVec);
			rowVec.clear();
		}

	}
	else
	{
		for (int y = 0; y < Squaresy; y++)
		{
			for (unsigned int x = 0; x < Squaresx; x++)
			{
				if ((rand() % 5) == 1)
				{
					mine = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "M");
					mine->callback(buttonCallback, view);
					rowVec.push_back(mine);

				}
				else
				{
					normal = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "N");
					normal->callback(buttonCallback, view);
					rowVec.push_back(normal);
				}
			}
			swag.push_back(rowVec);
			rowVec.clear();
		}
	}
}
void Board::setDebug(bool x) {
	debug = x;
}
bool Board::getDebug() {
	return debug;
}

int Board::handle_key(int e, int key, bool shift) {
	if (shift)
	{
		switch (key) {
		case 'd':
			this->do_callback();
			//cout << "YES" << endl;
			//cout << debug << endl;
			return 1;
		default:
			//cout << "NO" << endl;
			return 1;
		}
	}
}

int Board::handle(int e)
{
	switch (e) {
	case FL_KEYBOARD:
		this->handle_key(e, Fl::event_key(), Fl::get_key(FL_Shift_L));
		cout << "FL_KEYBOARD" << endl;
	case FL_FOCUS:
		label("Gained focus");
		return 1;
	case FL_UNFOCUS:
		label("Lost focus");
		damage(1);
		return 1;
	default:
		return Fl_Window::handle(e);
	};
}
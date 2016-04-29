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

void Board::modeChanger(Fl_Widget* widget, Board* board) {
	cout << "mode changer" << endl;
	bool mode = board->getDebug();
	Square* square = static_cast<Square*>(widget);
	unsigned int wide = board->wide;
	unsigned int tall = board->tall;
	unsigned int x = 0;
	unsigned int y = 0;
	bool status = board->getDebug();

	for (x = 0; x <= wide; x++) {
		for (y = 0; y <= tall; y++) {
			square = board->gameboard.at(x).at(y);
			if (square->getTag() == "M") {
				if (status) {
					square->setLabel("M");
					square->redraw();
					board->setDebug(false);
				}
				else if (!status){
					square->setLabel(" ");
					square->redraw();
					board->setDebug(true);
				}
			}
		}
	}
}

void Board::squarePressed(Fl_Widget* widget) {

	Square* square = static_cast<Square*>(widget);
	bool fcheck = square->getFcheck();

	if (fcheck == true) {
		if (square->getFlag()) {
			square->setImage("squareimages/coveredTile.jpg");
			square->redraw();
			square->setFlag(false);
		}
		else if (!(square->getFlag())) {
			square->setImage("squareimages/flaggedMine.jpg");
			square->redraw();
			square->setFlag(true);
		}
		
	}
	else if (fcheck == false)
	{
		if (square->getTag() == "M") {
			square->setImage("squareimages/mine.jpg");
			square->redraw();
			cout << "YOU LOSE" << endl;
			//FIXME new game 
		}
		else if (square->getTag() == "N") {
			cout << "non-mine" << endl;
			square->setImage("squareimages/emptyUncoveredTile.jpg");
			square->redraw();
			//FIXME function to put in number and check squares around
		}
	}
}

Board::Board(int width, int height, int Squaresx, int Squaresy,bool debugger, vector<string> imageNames) : debug(debugger), wide(Squaresx), tall (Squaresy),
	Fl_Window(width, height)
{
	srand(time(NULL)); //Sets random to be even more random!
	color(FL_BLACK); //board
	//vector < vector<Square*> > gameboard;
	vector <Square *> rowVec;
	unsigned int x;
	unsigned int y;
	void* view = static_cast<void*>(this);
	for (y = 0; y < Squaresy; y++)
	{
		for (x = 0; x < Squaresx; x++)
		{
			if ((rand() % 5) == 1)
			{
				mine = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "M", false);
				mine->callback(buttonCallback, view);
				rowVec.push_back(mine);
			}
			else
			{
				normal = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "N", false);
				normal->callback(buttonCallback, view);
				rowVec.push_back(normal);
			}
		}
		gameboard.push_back(rowVec);
		rowVec.clear();
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
		return 1;
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


















/*}
else
{
for (int y = 0; y < Squaresy; y++)
{
for (unsigned int x = 0; x < Squaresx; x++)
{
if ((rand() % 5) == 1)
{
mine = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "M", false);
mine->callback(buttonCallback, view);
rowVec.push_back(mine);

}
else
{
normal = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "N", false);
normal->callback(buttonCallback, view);
rowVec.push_back(normal);
}
}
gameboard.push_back(rowVec);
rowVec.clear();
}
}*/
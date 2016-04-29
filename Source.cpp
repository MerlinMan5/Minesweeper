#include "Board.h"
#include "Square.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


void boardCallback(Fl_Widget* widget1, void* boardptr) {
	cout << "boardCallback" << endl;
	Board* board = static_cast<Board*>(boardptr);

	board->modeChanger(widget1, board);
}

int main(int argc, char **argv)
{

	int wide = 0;
	int tall = 0;
	bool debugger = false;
	string input = "";

	cout << "How many squares wide and how many tall? (x,y): " << endl;
	cin >> wide;
	cin >> tall;
	/*cout << "Debug:" << endl;
	cin >> input;
	if (input == "yes")
	{
		debug = true;
	}
	else
	{
		debug = false;
	}*/

	vector <string> imageNames = {"squareimages/coveredTile.jpg", "squareimages/emptyUncoveredTile.jpg", "squareimages/mine.jpg",
		"squareimages/flaggedMine.jpg", "squareimages/coveredMineForDebugOnly.jpg", "squareimages/incorrectMine.jpg", "squareimages/losingMine.jpg", "images/question.jpg"};

	Board* gameBoard = new Board((16 * wide), (16)*tall, wide, tall,debugger, imageNames);
	gameBoard->show(0, nullptr);
	gameBoard->callback(boardCallback, nullptr);
	return Fl::run();


}



#include "Board.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
bool debug;

int main(int argc, char **argv)
{
	/*int wide = 0;
	int tall = 0;
	debug = false;
	string input = "";*/

	/*cout << "How many squares wide and how many tall? (x,y): " << endl;
	cin >> wide;
	cin >> tall;
	cout << "Debug:" << endl;
	cin >> input;

	if (input == "yes")
	{
		debug = true;
	}*/

	int wide = 16;
	int tall = 16;
	debug = false;


	vector <string> imageNames = {"images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
		"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg"};
	Board* gameBoard = new Board((16 * wide), (16 * tall), wide, tall, debug, imageNames);
	gameBoard->show(0, nullptr);
	//gameBoard->callback(boardCallback, nullptr);
	return Fl::run();
	system("pause");
}

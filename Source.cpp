#include <Windows.H>
#include "Board.h"
#include "Menu.h"
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
	debug = false;

	vector <string> imageNames = {"images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
		"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg"};
	Board* gameBoard = new Board((16 * 16), (16 * 16), 16, 16, debug, imageNames);

	Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 16) - 25, 25);
	menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
	menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
	menu->add("&File/About", 0, Menu::MyMenuCallback);
	menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
	menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
	menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
	menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
	menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
	gameBoard->show(0, nullptr);
	return Fl::run();
	system("pause");
}

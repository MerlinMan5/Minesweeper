#include "Board.h"
#include "Menu.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Timer.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <sstream>
#include <time.h>
#include <vector>
#include <string>
#include <FL/Fl_Output.H>
#include <fstream>


using namespace std;
bool debug;
string tostr(int a);
//static int count = 0;
Fl_Box *clock_box;

static void Timer_CB(void *data)
{
	static int t = 0;
	t++;
	string sval = tostr(t);
	clock_box->copy_label(sval.c_str());
	Fl::repeat_timeout(1.0, Timer_CB, data);
}

string tostr(int a)
{
	stringstream s;
	s << a;
	return s.str();
}

int main(int argc, char **argv)
{
	vector <string> imageNames = {"images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
		"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg"};
	Board* gameBoard = new Board((16 * 16), (16 * 16), 16, 16, debug, imageNames);

	//Fl_Output *flags = new Fl_Output(100, 1, 100,100, "yo");


	Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 16), 25);
	menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
	menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
	menu->add("&File/About", 0, Menu::MyMenuCallback);
	menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
	menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
	menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
	menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
	menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
	clock_box = new Fl_Box((16 * 16) - 25, 0, 25, 25, "0");

	gameBoard->show(0, nullptr);
	Fl::add_timeout(1.0, Timer_CB);

	return Fl::run();
	system("pause");
}
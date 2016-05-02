#include <Windows.H>
#include "Menu.h"
#include "Board.h"
#include <stdio.h>			// fprintf()
#include <stdlib.h>			// exit()
#include <string.h>	
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_message.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/filename.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
string str1;
string tostr2(int a);
Fl_Box *clock_boxn;
Fl_Box *clock_boxe;
Fl_Box *clock_boxm;
Fl_Box *clock_boxh;
Fl_Box *clock_boxc;

static void Timer_CBn(void *data)
{
static int n = 0;
	n++;
	string sval = tostr2(n);
	clock_boxn->copy_label(sval.c_str());
	Fl::repeat_timeout(1.0, Timer_CBn, data);
}

static void Timer_CBe(void *data)
{
	static int e = 0;
	e++;
	string sval = tostr2(e);
	clock_boxe->copy_label(sval.c_str());
	Fl::repeat_timeout(1.0, Timer_CBe, data);
}

static void Timer_CBm(void *data)
{
	static int m = 0;
	m++;
	string sval = tostr2(m);
	clock_boxm->copy_label(sval.c_str());
	Fl::repeat_timeout(1.0, Timer_CBm, data);
}

static void Timer_CBh(void *data)
{
	static int h = 0;
	h++;
	string sval = tostr2(h);
	clock_boxh->copy_label(sval.c_str());
	Fl::repeat_timeout(1.0, Timer_CBh, data);
}

static void Timer_CBc(void *data)
{
	static int c = 0;
	c++;
	string sval = tostr2(c);
	clock_boxc->copy_label(sval.c_str());
	Fl::repeat_timeout(1.0, Timer_CBc, data);
}

string tostr2(int a)
{
	stringstream s;
	s << a;
	return s.str();
}

int toint(string a)
{
	int i;
	stringstream s(a);
	s >> i;
	return i;
}

void Menu::MyMenuCallback(Fl_Widget *w, void *)
{
	Fl_Menu_Bar *bar = (Fl_Menu_Bar*)w;				// Get the menubar widget
	const Fl_Menu_Item *item = bar->mvalue();			// Get the menu item that was picked
	str1 = item->label();
	if (str1.compare("&New Game") == 0)
	{
		vector <string> imageNames = { "images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg" };
		Board* gameBoard1 = new Board((16 * 16), (16 * 16), 16, 16, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 16), 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		clock_boxn = new Fl_Box((16 * 16) - 25, 0, 25, 25, "0");
		gameBoard1->show(0, nullptr);
		Fl::add_timeout(1.0, Timer_CBn);
		Fl::run();
	}
	if (str1.compare("Fastest &Times") == 0)
	{

	}
	if (str1.compare("About") == 0)
	{
		Fl_Window* win = new Fl_Window(427,300);
		Fl_Box *words = new Fl_Box(200, 25, 26, 25, "The Developers of this Project are Jonathan Arauco, Quintin Calvin,\n Rishub Mishra, and sometimes Nick Cropper");
		Fl_Box *pic = new Fl_Box(120, 75, 200, 200);
		string pict = "squad.jpg";
		Fl_JPEG_Image j(pict.c_str());
		
		
		Fl_JPEG_Image* picc = new Fl_JPEG_Image(pict.c_str());
		pic->image(picc);
		pic->redraw();
		//pic->image(j);
		win->show();
		
	}
	if (str1.compare("&Quit") == 0)
	{
		exit(0);
	}
	if (str1.compare("Easy") == 0)
	{
		vector <string> imageNames = { "images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg" };
		Board* gameBoard2 = new Board((16 * 9), (16 * 9), 9, 9, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 9), 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		clock_boxe = new Fl_Box((16 * 9) - 25, 0, 25, 25, "0");
		gameBoard2->show(0, nullptr);
		Fl::add_timeout(1.0, Timer_CBe);
		Fl::run();
	}
	if (str1.compare("Medium") == 0)
	{
		vector <string> imageNames = { "images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg" };
		Board* gameBoard3 = new Board((16 * 16), (16 * 16), 16, 16, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 16), 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		clock_boxm = new Fl_Box((16 * 16) - 25, 0, 25, 25, "0");
		gameBoard3->show(0, nullptr);
		Fl::add_timeout(1.0, Timer_CBm);
		Fl::run();

	}
	if (str1.compare("Expert") == 0)
	{
		vector <string> imageNames = { "images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg" };
		Board* gameBoard3 = new Board((16 * 30), (16 * 16), 30, 16, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 30), 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		clock_boxh = new Fl_Box((16 * 30) - 25, 0, 25, 25, "0");
		gameBoard3->show(0, nullptr);
		Fl::add_timeout(1.0, Timer_CBh);
		Fl::run();
	}

	if (str1.compare("Custom") == 0)
	{
		int row;
		string roww = fl_input("Enter number of rows");
		row = toint(roww);
		int col;
		string coll = fl_input("Enter number of columns");
		col= toint(coll);

		vector <string> imageNames = { "images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg" };
		Board* gameBoard3 = new Board((16 * row), (16 * col), row, col, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * row), 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		clock_boxc = new Fl_Box((16 *row) - 25, 0, 25, 25, "0");
		gameBoard3->show(0, nullptr);
		Fl::add_timeout(1.0, Timer_CBc);
		Fl::run();
	}
}
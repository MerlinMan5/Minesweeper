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

using namespace std;
string str1;

void Menu::MyMenuCallback(Fl_Widget *w, void *)
{
	Fl_Menu_Bar *bar = (Fl_Menu_Bar*)w;				// Get the menubar widget
	const Fl_Menu_Item *item = bar->mvalue();			// Get the menu item that was picked
	str1 = item->label();
	if (str1.compare("&New Game") == 0)
	{
		vector <string> imageNames = {"images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg"};
		Board* gameBoard1 = new Board((16 * 16), (16 * 16), 16, 16, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 16) - 25, 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		gameBoard1->show(0, nullptr);
		Fl::run();
	}
	if (str1.compare("Fastest &Times") == 0)
	{

	}
	if (str1.compare("About") == 0)
	{
		fl_message("Developers for this project are Jonathan Aruco, Quintin Calvin, and Rishub Mishra.");
		Fl_Box *box = new Fl_Box(230, 0, 26, 25, "17");
		box->box(FL_UP_BOX);
	}
	if (str1.compare("&Quit") == 0)
	{
		exit(0);
	}
	if (str1.compare("Easy") == 0)
	{
		vector <string> imageNames = {"images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg"};
		Board* gameBoard2 = new Board((16 * 9), (16 * 9), 9, 9, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 9) - 25, 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		gameBoard2->show(0, nullptr);
		Fl::run();
	}
	if (str1.compare("Medium") == 0)
	{
		vector <string> imageNames = {"images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg"};
		Board* gameBoard3 = new Board((16 * 16), (16 * 16), 16, 16, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 16) - 25, 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		gameBoard3->show(0, nullptr);
		Fl::run();

	}
	if (str1.compare("Expert") == 0)
	{
		vector <string> imageNames = {"images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg"};
		Board* gameBoard3 = new Board((16 * 30), (16 * 16), 30, 16, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * 30) - 25, 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		gameBoard3->show(0, nullptr);
		Fl::run();

	}
	if (str1.compare("Custom") == 0)
	{
		int row;
		int col;
		int mines;
		cout << "Input rows and columbs, and mines" << endl;
		cin >> row;
		cin >> col;
		cin >> mines;

		vector <string> imageNames = {"images/coveredTile.jpg", "images/emptyUncoveredTile2.jpg", "images/mine.jpg",
			"images/flaggedMine.jpg", "images/coveredMineForDebugOnly.jpg", "images/incorrectMine.jpg", "images/losingMine.jpg", "images/question.jpg"};
		Board* gameBoard3 = new Board((16 * row), (16 * col), row, col, false, imageNames);
		Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, (16 * row) - 25, 25);
		menu->add("&File/&New Game", "^n", Menu::MyMenuCallback, 0, FL_MENU_DIVIDER);
		menu->add("&File/Fastest &Times", "^t", Menu::MyMenuCallback);
		menu->add("&File/About", 0, Menu::MyMenuCallback);
		menu->add("&File/&Quit", "^q", Menu::MyMenuCallback);
		menu->add("&Difficulty/Easy", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Medium", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Expert", 0, Menu::MyMenuCallback);
		menu->add("&Difficulty/Custom", 0, Menu::MyMenuCallback);
		gameBoard3->show(0, nullptr);
		Fl::run();
	}
}

void Menu::DiffCallback(Fl_Widget *w, void *)
{
	Fl_Menu_Bar *bar = (Fl_Menu_Bar*)w;
	const Fl_Menu_Item *item = bar->mvalue();

	char ipath[256]; bar->item_pathname(ipath, sizeof(ipath));


}
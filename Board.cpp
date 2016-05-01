#include <Windows.H>
#include "Board.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

int Board::totalMines(vector<vector<Square*>>& gameboard)
{
	int totalMines = 0;
	for (int i = 0; i < gameboard.size(); i++)
	{
		for (int k = 0; k < gameboard.at(i).size(); k++)
		{
			if ((gameboard.at(i).at(k)->getTag() == "M"))
			{
				totalMines++;
			}
		}
	}
	return totalMines;
}

void Board::checkWin(vector<vector<Square*>>& gameboard)
{
	int totalmines = totalMines(gameboard);
	int minesFlagged = 0;

	//check for win:  All mines flagged
	for (int i = 0; i < gameboard.size(); i++)
	{
		for (int k = 0; k < gameboard.at(i).size(); k++)
		{
			if ((gameboard.at(i).at(k)->getTag() == "M") && (gameboard.at(i).at(k)->getRightClick() == "F"))
			{
				minesFlagged++;
			}
		}
	}

	if (totalmines == minesFlagged)
	{

		for (int i = 0; i < gameboard.size(); i++)
		{
			for (int k = 0; k < gameboard.at(i).size(); k++)
			{
				if (gameboard.at(i).at(k)->getTag() == "M")
				{
					gameboard.at(i).at(k)->setImage("images/mine.jpg");
				}
				if (gameboard.at(i).at(k)->getTag() == "N")
				{
					gameboard.at(i).at(k)->setImage("images/smiley.jpg");
				}
				redraw();
			}
		}


		gameover = true;
		Fl_Window *window = new Fl_Window(260, 100);
		Fl_Box *box = new Fl_Box(0, -25, 260, 100, "YOU WIN!");
		box->box(FL_UP_BOX);
		box->labelsize(36);
		box->labelfont(FL_BOLD + FL_ITALIC);
		box->labeltype(FL_SHADOW_LABEL);
		Fl_Box *box2 = new Fl_Box(15, 17, 230, 100, "New Game? \n (1) Close this window \n (2) Check out our menu bar!");
		box2->labelsize(12);
		window->end();
		window->show();
	}

}

void buttonCallback(Fl_Widget* widget, void* boardPtr)
{
	Board* board = static_cast<Board*>(boardPtr);
	board->squarePressed(widget);
}

Board::Board(int width, int height, int Squaresx, int Squaresy, bool debug, vector<string> imageNames) :
	Fl_Window(width, height + 25, "Minesweeper!")
{

	Fl_Box *box = new Fl_Box(230, 0, 26, 25, "17");
	box->box(FL_UP_BOX);
	vector<Square*> rowVec;
	srand(time(NULL)); //Sets random to be even more random!
	color(FL_BLACK); //board

	void* view = static_cast<void*>(this);


	for (int y = 0; y < Squaresy; y++)
	{
		for (unsigned int x = 0; x < Squaresx; x++)
		{
			if ((rand() % 6) == 1)
			{
				mine = new Square((16 * x), (16 * y) + 25, 16, 16, " ", imageNames.at(0), "M", " ", true, this);
				mine->callback(buttonCallback, view);
				rowVec.push_back(mine);

			}
			else
			{
				normal = new Square((16 * x), (16 * y) + 25, 16, 16, "", imageNames.at(0), "N", " ", true, this);
				normal->callback(buttonCallback, view);
				rowVec.push_back(normal);
			}
		}
		gameboard.push_back(rowVec);
		rowVec.clear();
	}

}

void Board::squarePressed(Fl_Widget* widget)
{
	Square* square = static_cast<Square*>(widget);

	if (gameover == false)
	{

		if ((square->getRightClick() == "F") || (square->getRightClick() == "?"))
		{
			return;
		}

		if (square->getTag() == "M")
		{
			int x = this->x();
			int y = this->y();

			for (int i = 0; i < gameboard.size(); i++)
			{
				for (int k = 0; k < gameboard.at(i).size(); k++)
				{
					if (gameboard.at(i).at(k)->getTag() == "M")
					{
						gameboard.at(i).at(k)->setImage("images/mine.jpg");
					}
					if ((gameboard.at(i).at(k)->getTag() == "N") && (gameboard.at(i).at(k)->getRightClick() == "F"))
					{
						gameboard.at(i).at(k)->setImage("images/incorrectMine.jpg");
					}
					redraw();
				}
			}

			gameover = true;

			Fl_Window *window = new Fl_Window(260, 100);
			Fl_Box *box = new Fl_Box(0, -25, 260, 100, "YOU LOSE!");
			box->box(FL_UP_BOX);
			box->labelsize(36);
			box->labelfont(FL_BOLD + FL_ITALIC);
			box->labeltype(FL_SHADOW_LABEL);
			Fl_Box *box2 = new Fl_Box(15, 17, 230, 100, "New Game? \n (1) Close this window \n (2) Check out our menu bar!");
			box2->labelsize(12);
			window->end();
			window->show();

			square->setImage("images/losingMine.jpg");
			square->redraw();
		}
		else if (square->getTag() == "N")
		{
			countMines(gameboard, (widget->x()) / 16, (widget->y() - 25) / 16);

			square->redraw();
		}
	}
}

int Board::checkSurrounding(vector<vector<Square*>>& board, int x, int y)
{
	int width = board.at(0).size();
	int height = board.size();
	int nearbyMines = 0;

	if ((y - 1 >= 0) && (x + 1 < width))
	{
		if (board.at(y - 1).at(x + 1)->getTag() == "M")
		{
			nearbyMines++;
			//cout << "top right" << endl;
		}
	}

	if ((y - 1 >= 0))
	{
		if (board.at(y - 1).at(x)->getTag() == "M")
		{
			nearbyMines++;
			//cout << "up" << endl;
		}
	}

	if ((y - 1 >= 0) && (x - 1 >= 0))
	{
		if (board.at(y - 1).at(x - 1)->getTag() == "M")
		{
			nearbyMines++;
			//cout << "top left" << endl;
		}
	}

	if (x - 1 >= 0)
	{
		if (board.at(y).at(x - 1)->getTag() == "M")
		{
			nearbyMines++;
			//cout << "left" << endl;
		}
	}

	if (x + 1 < width)
	{
		if (board.at(y).at(x + 1)->getTag() == "M")
		{
			nearbyMines++;
			//cout << "right" << endl;
		}
	}

	if ((y + 1 < height))
	{
		if (board.at(y + 1).at(x)->getTag() == "M")
		{
			nearbyMines++;
			//cout << "down" << endl;
		}
	}

	if ((y + 1 < height) && (x - 1 >= 0))
	{
		if (board.at(y + 1).at(x - 1)->getTag() == "M")
		{
			nearbyMines++;
			//cout << "bottom left" << endl;
		}
	}

	if ((y + 1 < height) && (x + 1 < width))
	{
		if (board.at(y + 1).at(x + 1)->getTag() == "M")
		{
			nearbyMines++;
			//cout << "bottom right" << endl;
		}
	}

	return nearbyMines;
}

void Board::countMines(vector < vector<Square*> > &board, int x, int  y)
{
	vector <string> numberNames = {"images/emptyUncoveredTile2.jpg", "images/1.jpg", "images/2.jpg", "images/3.jpg",
		"images/4.jpg", "images/5.jpg", "images/6.jpg", "images/7.jpg", "images/8.jpg"};

	board.at(x).at(y)->setIsCovered(false);
	int nearbyMines = checkSurrounding(board, x, y);

	if (nearbyMines == 0)
	{
		if (x > 0)
		{
			if (gameboard.at(x - 1).at(y)->getIsCovered())
			{
				countMines(board, x - 1, y);
			}
			if (y > 0 && gameboard.at(x - 1).at(y - 1)->getIsCovered())
			{
				countMines(board, x - 1, y - 1);
			}
			if (y < (gameboard.size() - 1) && gameboard.at(x - 1).at(y + 1)->getIsCovered())
			{
				countMines(board, x - 1, y + 1);
			}
		}
		if (x < (gameboard.size() - 1))
		{
			if (gameboard.at(x + 1).at(y)->getIsCovered())
			{
				countMines(board, x + 1, y);
			}
			if (y > 0 && gameboard.at(x + 1).at(y - 1)->getIsCovered())
			{
				countMines(board, x + 1, y - 1);
			}
			if (y < (gameboard.size() - 1) && gameboard.at(x + 1).at(y + 1)->getIsCovered())
			{
				countMines(board, x + 1, y + 1);
			}
		}
		if (y > 0 && gameboard.at(x).at(y - 1)->getIsCovered())
		{
			countMines(board, x, y - 1);
		}
		if (y < (gameboard.size() - 1) && gameboard.at(x).at(y + 1)->getIsCovered())
		{
			countMines(board, x, y + 1);
		}
	}
	board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
	board.at(y).at(x)->redraw();
}

int Board::handle_key(int e, int key, bool shift)
{
	string name;
	if (shift)
	{
		switch (key)
		{
		case 'd':
			debugIterator++;

			if ((debugIterator % 2) != 0)
			{
				name = "images/mine.jpg";
			}
			else
			{
				name = "images/coveredTile.jpg";
			}

			for (int i = 0; i < gameboard.size(); i++)
			{
				for (int k = 0; k < gameboard.at(i).size(); k++)
				{
					if (gameboard.at(i).at(k)->getTag() == "M")
					{
						gameboard.at(i).at(k)->setImage(name);
						redraw();
					}
				}
			}
			return 0;
		default:
			return 0;
		}
	}
}

int Board::handle(int e)
{
	switch (e)
	{
	case FL_KEYBOARD:
		this->handle_key(e, Fl::event_key(), Fl::get_key(FL_Shift_L));
		return 0;
	default:
		return Fl_Window::handle(e);
	};
}

//int minesNotFlagged(vector<vector<Square*>>& gameboard)
//{
//	totalMines(gameboard);
//}
//
//int minesFlagged(vector<vector<Square*>>& gameboard)
//{
//	int flaggedMines = 0;
//	for (int i = 0; i < gameboard.size(); i++)
//	{
//		for (int k = 0; k < gameboard.at(i).size(); k++)
//		{
//			if (gameboard.at(i).at(k)->getRightClick() == "F")
//			{
//				gameboard.at(i).at(k)->setImage("images/incorrectMine.jpg");
//				flaggedMines++;
//				//redraw();
//			}
//		}
//	}
//
//	return flaggedMines++;
//}
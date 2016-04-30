#include "Board.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

int checkSurrounding(vector < vector<Square*> > &board, int x, int  y);
void countMines(vector < vector<Square*> > &board, int y, int  x);

int totalMines(vector<vector<Square*>>& gameboard)
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

void checkWin(vector<vector<Square*>>& gameboard)
{
	int totalmines = totalMines(gameboard);
	cout << "totalMinesIn:" << totalmines << endl;
	int minesFlagged = 0;
	//check for win:  All mines flagged
	for (int i = 0; i < gameboard.size(); i++)
	{
		for (int k = 0; k < gameboard.at(i).size(); k++)
		{
			if ((gameboard.at(i).at(k)->getTag() == "M") && (gameboard.at(i).at(k)->getRightClick() == "F" ))
			{
				minesFlagged++;
			}
		}
	}
	cout << "total mines: " << totalmines << " flagged: " << minesFlagged << endl;
	if (totalmines == minesFlagged)
	{
		cout << "you win!" << endl;
	}
}

void buttonCallback(Fl_Widget* widget, void* boardPtr)
{
	//cout << "callback called!" << endl;
	Board* board = static_cast<Board*>(boardPtr);
	board->squarePressed(widget);
	//checkWin(gameboard)
}

Board::Board(int width, int height, int Squaresx, int Squaresy, bool debug, vector<string> imageNames) :
	Fl_Window(width, height + 32, "Minesweeper!")
{
	vector<Square*> rowVec;
	srand(time(NULL)); //Sets random to be even more random!
	color(FL_BLACK); //board

	unsigned int x;
	unsigned int y;
	void* view = static_cast<void*>(this);


	for (int y = 0; y < Squaresy; y++)
	{
		for (unsigned int x = 0; x < Squaresx; x++)
		{
			if ((rand() % 6) == 1)
			{
				mine = new Square((16 * x), (16 * y), 16, 16, " ", imageNames.at(0), "M", " ");
				mine->callback(buttonCallback, view);
				rowVec.push_back(mine);

			}
			else
			{
				normal = new Square((16 * x), (16 * y), 16, 16, "", imageNames.at(0), "N", " ");
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

	//Blocks action if flagged or questioned
	if ((square->getRightClick() == "F") || (square->getRightClick() == "?"))
	{
		return;
	}

	if (square->getTag() == "M")
	{
		int x = this->x();
		int y = this->y();
		cout << "YOU LOSE" << endl;

		for (int i = 0; i < gameboard.size(); i++)
		{
			for (int k = 0; k < gameboard.at(i).size(); k++)
			{
				if (gameboard.at(i).at(k)->getTag() == "M")
				{
					gameboard.at(i).at(k)->setImage("images/mine.jpg");
					redraw();
				}
			}
		}
		square->setImage("images/losingMine.jpg");
		square->redraw();
	}
	else if (square->getTag() == "N")
	{
		countMines(gameboard, widget->x(), widget->y());
		square->redraw();
	}

	checkWin(gameboard);
}

int checkSurrounding(vector<vector<Square*>>& board, int x, int y)
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

void countMines(vector < vector<Square*> > &board, int x, int  y)
{
	vector <string> numberNames = {"images/emptyUncoveredTile2.jpg", "images/1.jpg", "images/2.jpg", "images/3.jpg",
		"images/4.jpg", "images/5.jpg", "images/6.jpg", "images/7.jpg", "images/8.jpg"};

	int width = board.at(0).size();
	int height = board.size();
	x = (x / 16);
	y = (y / 16);
	int nearbyMines = checkSurrounding(board, x, y);

	int tempx = x;
	int tempy = y;

	//if (nearbyMines == 0)
	//{
	//	int x1 = x + 1;
	//	int y1 = y + 1;
	//	int x2 = x - 1;
	//	int y2 = y - 1;

		//if (x - 1 >= 0)
		//{
		//	board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
		//	board.at(y).at(x)->redraw();
		//	countMines(board, (x2)* 16, y * 16);
		//}

		//if (y - 1 >= 0)
		//{
		//	board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
		//	board.at(y).at(x)->redraw();
		//	countMines(board, (x)* 16, (y2)* 16);
		//}

		/*	x1 = tempx + 1;
			y1 = tempy + 1;
			x2 = tempx - 1;
			y2 = tempy - 1;

			if (x + 1 < width)
				{
					board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
					board.at(y).at(x)->redraw();
					countMines(board, (x1)* 16, y * 16);
				}
				if (y + 1 < height)
				{
					board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
					board.at(y).at(x)->redraw();
					countMines(board, (x)* 16, (y1)* 16);
				}*/

				/*
				if ((x - 1 >= 0) && (y - 1 >= 0))
				{
					board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
					board.at(y).at(x)->redraw();
					countMines(board, (x2)* 16, (y2)* 16);
				}
				if ((x + 1 < width) && (y + 1 < height))
				{
					board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
					board.at(y).at(x)->redraw();
					countMines(board, (x1)* 16, (y1)* 16);
				}
				if ((x - 1 >= 0) && (y + 1 < height))
				{
					board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
					board.at(y).at(x)->redraw();
					countMines(board, (x2)* 16, (y1)* 16);
				}
				if ((x + -1 < width) && (y - 1 < height))
				{
					board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
					board.at(y).at(x)->redraw();
					countMines(board, (x1)* 16, (y2)* 16);
				}*/

	/*}
	else
	{*/
		board.at(y).at(x)->setImage(numberNames.at(nearbyMines));
		board.at(y).at(x)->redraw();
	//}
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



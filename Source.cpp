#include "Board.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.h>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	int wide = 0;
	int tall = 0;
	bool debug = false;
	string input = "";

	cout << "How many squares wide and how many tall? (x,y): " << endl;
	cin >> wide;
	cin >> tall;
	cout << "Debug:" << endl;
	cin >> input;
	if (input == "yes")
	{
		debug = true;
	}
	else
	{
		debug = false;
	}


		Board* gameBoard = new Board((16*wide), (16)*tall, wide, tall, debug);
	gameBoard->show(argc, argv);
	return Fl::run();


	//^Above button with click response (No Images)
//********************************************************
	//Below is boxes with Images (No click response)


	//string file1 = "images/CoveredTile.jpg";
	//string file2 = "images/mine.jpg";
	//Fl_JPEG_Image img1(file1.c_str());
	//Fl_JPEG_Image img2(file2.c_str());

	//Fl_Window *window = new Fl_Window((17*wide), 16*tall);

	//srand(time(NULL));//Sets random to be even more random!

	//for (int y = 0; y < tall; y++)
	//{
	//	for (int x = 0; x < wide; x++)
	//	{
	//		if ((rand() % 5) == 1)
	//		{
	//			Cell* cell = new Cell(5 + (16 * x), (16 * y) - 7, 16, 16, "");
	//			cell->image(img2);
	//		}
	//		else
	//		{
	//			Cell* cell = new Cell(5 + (16 * x), (16 * y) - 7, 16, 16, "");
	//			cell->image(img1);
	//		}
	//	}
	//}
	//

	//window->show(argc, argv);
	//return Fl::run();


}

//********************************************************

//#include <iostream>
//#include <vector>
//#include <time.h> 
//
//using namespace std;
//
////takes a width and height and makes a board of random 1's and 0's
//vector<vector<int>> makeBoard(const int wide, const int tall)
//{
//	vector < vector<int> > board;
//	vector <int> rowVec;
//	srand(time(NULL)); //Sets random to be even more random!
//
//
//	for (int k = 0; k < tall; k++)
//	{
//		for (unsigned int i = 0; i < wide; i++)
//		{
//			rowVec.push_back(rand() % 2);
//		}
//		board.push_back(rowVec);
//		rowVec.clear();
//	}
//	return board;
//}
//
////takes the board and prints each element out
//void printBoard(const vector <vector<int> > &board)
//{
//	for (unsigned int i = 0; i < board.size(); i++)
//	{
//		for (unsigned int k = 0; k < board.at(i).size(); k++)
//		{
//			cout << board.at(i).at(k) << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
////takes the board, an x and y position, converts into a vector element and checks if it is a mine
//bool isMine(const vector <vector<int> > &board, const int x, const int y)
//{
//	bool isMine = false;
//
//	if (board.at(x - 1).at(y - 1) == 1)
//	{
//		isMine = true;
//	}
//
//	return isMine;
//}
//
////takes the board, an x and y position, converts into a vector element and checks if it is a edge piece
//bool isEdgePiece(const vector <vector<int> > &board, const int x, const int y)
//{
//	bool isEdge = false;
//
//	int width = board.at(0).size();
//	int height = board.size();
//
//	if ((x == width) || ((x - 1) == 0))
//	{
//		isEdge = true; //on left or right side
//	}
//	if ((y == height) || ((y - 1) == 0))
//	{
//		isEdge = true; //on top or bottom
//	}
//
//	return isEdge;
//
//}
//
////takes the board, an x and y position, converts into a vector element and checks if it is a mine
////TODO: Make this fucntion work for edge pieces
//int getNearbyMines(vector <vector<int> > &board, int x, int y)
//{
//	int nearbyMines = 0;
//
//	board.at(y-1).at(x-1) = 3; //the 'Clicked' square
//
//	if (isEdgePiece(board, x, y))
//	{
//		cout << "this doesnt work for edge pieces yet" << endl; 
//	}
//	else
//	{
//		//check the eight surrounding squares for a mine
//		if (board.at(y).at(x - 1) == 1)
//		{
//			nearbyMines++;
//			//cout << " above ";
//			board.at(y).at(x - 1) = 7;
//		}
//
//		if (board.at(y - 1).at(x) == 1)
//		{
//			nearbyMines++;
//			//cout << " right ";
//			board.at(y - 1).at(x) = 7;
//		}
//
//		if (board.at(y - 2).at(x - 1) == 1)
//		{
//			nearbyMines++;
//			//cout << " below ";
//			board.at(y - 2).at(x - 1) = 7;
//		}
//
//		if (board.at(y - 1).at(x - 2) == 1)
//		{
//			nearbyMines++;
//			//cout << " left ";
//			board.at(y - 1).at(x - 2) = 7;
//		}
//
//		if (board.at(y).at(x) == 1)
//		{
//			nearbyMines++;
//			cout << " top right ";
//			board.at(y).at(x) = 7;
//		}
//
//		if (board.at(y - 2).at(x) == 1)
//		{
//			nearbyMines++;
//			//cout << " bottom right";
//			board.at(y - 2).at(x) = 7;
//		}
//
//		if (board.at(y).at(x - 2) == 1)
//		{
//			nearbyMines++;
//			//cout << " top left";
//			board.at(y).at(x - 2) = 7;
//		}
//
//		if (board.at(y - 2).at(x - 2) == 1)
//		{
//			nearbyMines++;
//			//cout << " bottom left";
//			board.at(y - 2).at(x - 2) = 7;
//		}
//	}
//	return nearbyMines;
//}
//
//int main()
//{
//	int wide = 0;
//	int tall = 0;
//
//	cout << "How many squares wide and how many tall? (x,y): " << endl;
//	cin >> wide;
//	cin >> tall;
//	cout << endl;
//
//	vector < vector<int> > board = makeBoard(wide, tall);
//
//	printBoard(board);
//	cout << "hit: " << getNearbyMines(board, 2, 3) << endl;
//
//	printBoard(board);
//
//	system("pause");
//}
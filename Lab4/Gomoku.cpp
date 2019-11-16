#include "Gomoku.h"

using namespace std;
Gomoku::Gomoku() {
	string boardDisplay;
	boardDisplay += blank;
	int dimensions = 19;
	for (int row = 0; row < dimensions + 2; row++)
	{
		vector<string> piece;
		board.push_back(piece);
		for (int col = 0; col < 21; col++)
			board[row].push_back(boardDisplay); //initialize gameboard to empty
	}
	player = w; //start with piece W
	lastRow = 0; //initially no moves, used for efficiently checking game won
	lastCol = 0; //initially no moves, used for efficiently checking game won
	boardDisplay = b;
	bValidMoves = "Player " + boardDisplay + ": ";
	boardDisplay = w;
	wValidMoves = "Player " + boardDisplay + ": ";
	xDimensions = dimensions;
	yDimensions = dimensions;
	longestLength = player.length();


};

ostream& operator<<(ostream& cout, Gomoku const& gm) {
	string display = "";
	for (int row = 0; row < gm.yDimensions + 1; row++)
	{
		display += to_string(gm.yDimensions - row);
		for (int col = 0; col < gm.xDimensions + 1; col++)
		{
			if (gm.board[gm.yDimensions - row][col].length() == gm.longestLength)
				display += gm.board[gm.yDimensions - row][col] + " ";
			else
			{
				display += gm.board[gm.yDimensions - row][col];
				for (int i = 0; i < gm.longestLength; i++)
					display += " ";
			}
		}
		display += "\n";
	}
	display += " ";
	for (int i = 0; i < gm.xDimensions + 1; i++)
	{
		display += to_string(i) + " ";
	}
	cout << display << endl;
	return cout;
}

bool Gomoku::done() {
	//check each row:
	bool match = true;
	for (int row = 0; row < 19; row++) {
		for (int col = 0; col < 14; col++)
		{
			for (int i = 0; i < 5; i++) {
				if (board[row][col] != board[row][col + i] || board[row][col] == " ")
					match = false;
			}
			if (match) return true;
		}
	}
	//check each column:
	for (int col = 0; col < 19; col++) {
		for (int row = 0; row < 14; row++)
		{
			for (int i = 0; i < 5; i++) {
				if (board[row][col] == board[row + i][col] || board[row][col]== " ")
					match = false;
			}
			if (match) return true;
		}
	}
	//check diagonal lines from top-left to bottom-right
	for (int col = 0; col < 14; col++) {
		for (int row = 0; row < 14; row++) {
			{
				for (int i = 0; i < 5; i++) {
					if (board[row][col] != board[row + i][col + i] || board[row][col] == " ")
					match = false;
				}
				if (match) { return true; }
			}
		}
	}
	//lastly check diagonal lines from top-right to bottom-left
	for (int col = 19; col > 4; --col) {
		for (int row = 19; row > 4 ; --row)
		{
			for (int i = 0; i < 5; i++) {
				if (board[row][col] != board[row - i][col - i] || board[row][col] == " ")
					match = false;
			}
			if (match) return true;
		}
	}
	return false;
}

bool Gomoku::draw() {
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) { //we'll just check and see if there are open spaces on the board, if so then we're not done nor is there a draw
			if (board[i][j] == " ") {
				cout << board[i][j] << endl;
				return false;
			}
		}
	}
	if (done()) {
		return false;
	}
	else {
		return true;
	}
}

int Gomoku::turn() {
	//tell the user who's turn it is
	std::cout << player + "\'s turn" << endl;
	unsigned int r = 0;
	unsigned int c = 0;
	//prompt the user for input
	int res = prompt(r, c);
	if (res == quit)
		return quit; //user quit
	while ((res != success || board[c][r] != " ") && res != quit)
	{
		res = prompt(r, c); //user input incorrectly formatted
	}
	lastRow = r;
	lastCol = c;
	lastPiece = player;
	board[c][r] = lastPiece; //place piece on board
	print(); //print game board
	cout << " " << endl;
	if (player[pieceTurnIndex] == b) //add move to list of move for correct piece
	{
		bValidMoves += to_string(r) + ", " + to_string(c) + "; ";
		cout << bValidMoves << endl;
	}
	else if(player[pieceTurnIndex] == w)
	{
		wValidMoves += to_string(r) + ", " + to_string(c) + "; ";
		cout << wValidMoves << endl;
	}

	return res;
}

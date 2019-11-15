#include "TicTacToe.h"

int TicTacToe::turn() {
	//tell the user who's turn it is
	std::cout << player + "\'s turn" << endl;
	unsigned int r = 0;
	unsigned int c = 0;
	//prompt the user for input
	int res = prompt(r, c);
	if (res == quit)
		return quit; //user quit
	while ((res != success || board[r][c] != " ") && res != quit)
	{
		res = prompt(r, c); //user input incorrectly formatted
	}
	lastRow = r;
	lastCol = c;
	lastPiece = player;
	board[r][c] = lastPiece; //place piece on board
	print(); //print game board
	cout << " " << endl;
	if (player[pieceTurnIndex] == x) //add move to list of move for correct piece
	{
		xValidMoves += to_string(r) + ", " + to_string(c) + "; ";
		cout << xValidMoves << endl;
	}
	else
	{
		oValidMoves += to_string(r) + ", " + to_string(c) + "; ";
		cout << oValidMoves << endl;
	}
	return res;
}

TicTacToe::TicTacToe() {
	height = boardHeight;
	length = boardLen;
	lastRow = 0;
	lastCol = 0;
	for (int i = 0; i < height; ++i) { //generating the 2d array
		vector<string> row; //the vector to act as the row
		for (int j = 0; j < length; ++j) {
			row.push_back(" ");
		}
		board.push_back(row);
	}
	player = "x"; //we'll call the start "Y" just so that it's initialized, and account for this in our case switch
	longestLength = player.length();
}



bool TicTacToe::draw() {
	for (int i = 1; i < height - 1; ++i) {
		for (int j = 1; j < length - 1; ++j) { //we'll just check and see if there are open spaces on the board, if so then we're not done nor is there a draw
			if (board[i][j] == " ") {
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

bool TicTacToe::done() {

	for (int i = 1; i < height - 1; ++i) {
		if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][1] != " ") { //check the rows
			return true;
		}
	}
	for (int i = 1; i < length - 1; ++i) {
		if (board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[1][i] != " ") { //check the columns
			return true;
		}
	}
	if (board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] != " ") { //checking the diagonals
		return true;
	}
	else if (board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[2][2] != " ") { //more checking a diagonal
		return true;
	}
	else {
		return false;
	}

}

ostream& operator<<(ostream& cout, TicTacToe const& tt) {
	string s = "";
	for (int r = 0; r < 5; r++)
	{
		s += to_string(4 - r);
		for (int c = 0; c < 5; c++)
		{
			int num = 4;
			if (tt.board[c][num - r].length() == tt.longestLength)
				s += tt.board[c][num - r] + " ";
			else
			{
				s += tt.board[c][num - r];
				for (int i = 0; i < tt.longestLength; i++)
					s += " ";
			}
		}
		s += "\n";
	}
	s += " 0 1 2 3 4";
	cout << s << endl;
	return cout;
}
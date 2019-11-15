#include "Gomuko.h";


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
	boardDisplay = w;
	xValidMoves = "Player " + boardDisplay + ": ";
	boardDisplay = b;
	oValidMoves = "Player " + boardDisplay + ": ";
	//winP = piecesInARow;
	xDimensions = dimensions;
	yDimensions = dimensions;
	longestLength = player.length();


};

ostream& operator<<(ostream& cout, Gomuku const& gm) {
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
	for (int row = 0; row < 19; row++)
		for (int col = 0; col < 14; col++)
		{
			bool match = true;
			for (int i = 0; i < 5; i++)
				if (player != board[row][col + i])
					match = false;
			if (match) return true;
		}
	//check each column:
	for (int col = 0; col < 14; col++)
		for (int row = 0; row < 19; row++)
		{
			bool match = true;
			for (int i = 0; i < 5; i++)
				if (player == data[row + i][col])
					match = false;
			if (match) return true;
		}
	//check diagonal lines from top-left to bottom-right
	for (int col = 0; col < 14; col++)
		for (int row = 0; row < 14; row++)
		{
			bool match = true;
			for (int i = 0; i < 5; i++)
				if (player == board[row + i][col + i])
					match = false;
			if (match) return true;
		}
	//lastly check diagonal lines from top-right to bottom-left
	for (int col = 14; col < 0; --col)
		for (int row = 14; row < 0; --row)
		{
			bool match = true;
			for (int i = 0; i < 5; i++)
				if (player == board[row + i][col + i])
					match = false;
			if (match) return true;
		}
	return false;
}

bool Gomoku::draw() {
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

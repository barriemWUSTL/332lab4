#include "Gomuko.h";


Gomuku::Gomuku() {
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


#include "GamePiece.h"
#include "exitCodes.h"
#include <vector>
#include <iostream>
#include "GameBoard.h"
using namespace std;


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
	player = "Y"; //we'll call the start "Y" just so that it's initialized, and account for this in our case switch
	longestLength = player.length();
}



bool TicTacToe::draw() {
	for (int i = 1; i < height-1; ++i) {
		for (int j = 1; j < length-1; ++j) { //we'll just check and see if there are open spaces on the board, if so then we're not done nor is there a draw
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

	for (int i = 1; i < height-1; ++i) {
		if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][1] != " ") { //check the rows
			return true;
		}
	}
	for (int i = 1; i < length-1; ++i) {
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

int GameBase::prompt(unsigned int& x, unsigned int& y) {
	string str;
	bool good = false;
	while (!good) {
		cout << endl<< "Please input coordinates for your next piece in the format 'x,y', or 'quit' to quit." << endl;
		cin >> str;
		string s = "quit";
		if (str == s) {
			return quit; //send the signal to the main to quit
		}
		else {
			if (str.length() != coordLen) { //the string length should be 3 if it's a proper coord, eg, 0,0
				continue;			 //this also keeps people from doing tomfoolery like "20,19"
			}
			else if (str[coordFirst] >= '1' && str[coordFirst] <= '3') {
				
				if (str[coordComma] == ',') {
					if (str[coordSecond] >= '1' && str[coordSecond] <= '3') {
						good = true;
					}
				}
			}
		}
	}
	x = str[coordFirst] - 48; //adjusting from a char to an int by subtracting 48, the ascii to int conversion of 0-9
	y = str[coordSecond] - 48;
	return success;
}

int TicTacToe::turn() {
	//tell the user who's turn it is
	cout << player + "\'s turn" << endl;
	unsigned int r = 0;
	unsigned int c = 0;
	//prompt the user for input
	int res = prompt(r, c);
	if (res == quit)
		return quit; //user quit
	while (res != success && res != quit)
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

//int GameBase::turn() {
//	unsigned int x, y, cont;
//	unsigned int& xx = x;
//	unsigned int& yy = y;
//	this->player = switchPlayer(this->player); //switching the player
//	bool valid = false;
//	while (!valid) {
//		cont = prompt(xx, yy); //prompting for the next move
//		if (cont == quit) {
//			return quit;
//		}
//		else if (board[y][x] == ' ') { //we're checking to see if the space is still open
//			board[y][x] = player; // setting the board
//			if (player == 'X') {
//				Move XMove = { player, x, y }; //we're storing the move in the moves vector
//				XMoves.push_back(XMove);
//			}
//			else {
//				Move OMove = { player, x, y };
//				OMoves.push_back(OMove); //see above
//
//			}
//			valid = true;
//		}
//		else {
//			cout << "Sorry, that space is already taken." << endl;
//			continue;
//		}
//	}
//	cout << *this << endl;
//	cout << "Player " << player << "'s moves: ";
//	if (player == 'X') {
//		for (int i = 0; i < XMoves.size(); ++i) {
//			cout << XMoves[i].x << ", " << XMoves[i].y << "; ";
//		}
//		cout << endl;
//	}
//	else if (player == 'O') {
//		for (int i = 0; i < OMoves.size(); ++i) {
//			cout << OMoves[i].x << ", " << OMoves[i].y << "; ";
//		}
//		cout << endl;
//	}
//	return success;
//}
int  GameBase::play() {
	print();
	int numTurns = 0;
	while (!done() && !draw()) //while the game isn't over, continue
	{
		if (player[pieceTurnIndex] == x) //switch piece playing to alternate turn and update variable keeping track of longest piece length
		{
			player = o;
			if (player.length() > longestLength)
				longestLength = player.length();
		}
		else if (player[pieceTurnIndex] == o)
		{
			player = x;
			if (player.length() > longestLength)
				longestLength = player.length();
		}
		else if (player[pieceTurnIndex] == b)
		{
			player = w;
			if (player.length() > longestLength)
				longestLength = player.length();
		}
		else
		{
			player = b;
			if (player.length() > longestLength)
				longestLength = player.length();
		}
		numTurns++;
		int res = turn();
		if (res == quit) //user quit
		{
			cout << player + " quit the game in " + to_string(numTurns) + " turns!" << endl;
			return res;
		}
	}
	if (done()) //game won
	{
		cout << player + " won the game in " + to_string(numTurns) + " turns!" << endl;
	}
	if (draw()) //game drew
	{
		cout <<  to_string(numTurns) + "turns were played. Unfortunately, a player chickened out and quit, ending the game prematurely" << endl;
	}
	return success; //error code 0, means the program executed successfully




}

//int GameBase::play() {
//	//cout << *this;
//
//	bool done = false; // we need our loop conditions
//	bool draw = false;
//	int gameState= 0; //we're also going to need an increment variable to count the number of turns
//	int turns = 0;
//	while (!done && !draw && gameState != quit) {
//		++turns;
//		gameState = turn();
//		done = GameBase::done(); //check our end conditions
//		draw = GameBase::draw();
//	}
//	if (done) {
//		char winner = this->player; //(*this).player
//		if (winner == 'X') {
//			cout << turns << " turns were played. Player " << winner << " was victorious!" << endl; //some nice win messages
//			return success;
//		}
//		else {
//			cout << turns << " turns were played. Player " << winner << " was victorious!" << endl; //rejected win message: player <X/Y> is the most epic gamer
//			return success;
//		}
//	}
//	else if (draw) { //checking if the reason it stopped is a draw
//		cout << turns << " turns were played. Since it was a draw, both players are losers!" << endl;
//		return exits::draw;
//	}
//	else if (gameState == quit) { //checking if the reason it stopped is someone quit
//		cout << turns << " turns were played. Unfortunately, a player chickened out and quit, ending the game prematurely." << endl;
//		return quit;
//	}
//	cout << "If you're seeing this, something has gone horribly wrong. Exit Code: 4" << endl; //I seriously hope nothing will happen that this will get to this, but
//	return somethingWentWrong; //if something causes execution to stop without one of the game state codes being changed, this will be thrown
//}

//this neat little function swaps the player back and forth
//X gets to go first, which I chose arbitrarily
//char switchPlayer(char player) {
//	switch (player) {
//	case 'Y': //We're initializing player with Y so we have a set case to start with
//		player = 'X';
//		break;
//	case 'X':
//		player = 'O'; //flip the players to change turns
//		break;
//	case 'O':
//		player = 'X';
//		break;
//	default:
//		player = 'X'; //X is very lucky, if something goes wrong they go.
//		break;
//	}
//	return player;
//}


//ostream& operator<<(ostream& cout, const TicTacToe& ttt) {
//	int a = (int) ttt.board.size() - 1; //generating the dimensions
//	int b = 0;
//	for (int i = ttt.board.size()-1; i >= 0; --i)
//	{
//		cout << a; // printing out the side coordinates
//		--a;
//		for (int j = 0; j < ttt.board[i].size(); ++j)
//		{
//			cout << ttt.board[i][j] << " "; //print out a row of the board
//		}		cout << endl; //move to the next row
//	}
//	for (int i = 0; i < ttt.board[0].size(); ++i) {
//		cout << " " << i; //print out bottom axes
//	}
//	return cout;
//}


ostream& operator<<(ostream& cout, TicTacToe const& tt) {
	string s = "";
	for (int r = 0; r < 5; r++)
	{
		s += to_string(4 - r);
		for (int c = 0; c < 5; c++)
		{
			int num = 4;
			if (tt.board[num - r][c].length() == tt.longestLength)
				s += tt.board[num - r][c] + " ";
			else
			{
				s += tt.board[num - r][c];
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

shared_ptr<GameBase> GameBase::pointer(int argc, char* argv[]) {
	if (argc != 0) {
		if (argv[1] == "TicTacToe") {
			//TicTacToe ttt = TicTacToe();
			shared_ptr<GameBase> ttt = make_shared<TicTacToe>();
			return ttt;
		}
	}
	else {
		return 0;
	}
}
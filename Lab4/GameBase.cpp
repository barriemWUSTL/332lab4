#include "GamePiece.h"
#include "exitCodes.h"
#include <vector>
#include <iostream>
#include "TicTacToe.h"
#include "Gomoku.h"
using namespace std;


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
			cout << "Invalid coordinates, please reenter" << endl;
			return invalidCoordinates;
		}
	}
	x = str[coordFirst] - 48; //adjusting from a char to an int by subtracting 48, the ascii to int conversion of 0-9
	y = str[coordSecond] - 48;
	return success;
}

int  GameBase::play() {
	print();
	int numTurns = 0;
	while (!done() && !draw()) //while the game isn't over, continue
	{
		if (name == "TicTacToe") {
			if (player[pieceTurnIndex] == x) //switch piece playing to alternate turn and update variable keeping track of longest piece length
			{
				player = o;
				if (player.length() > longestLength)
					longestLength = player.length();
			}
			else
			{
				player = x;
				if (player.length() > longestLength)
					longestLength = player.length();
			}
		}
		else {
		 if (player[pieceTurnIndex] == b)
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
		}
		numTurns++;
		int res = turn();
		if (res == quit) //user quit
		{
			cout << player + " quit the game after " + to_string(numTurns) + " turns!" << endl;
			return res;
		}
	}
	if (done()) //game won
	{
		cout << player + " won the game in " + to_string(numTurns) + " turns!" << endl;
	}
	if (draw()) //game drew
	{
		cout <<  to_string(numTurns) + " turns were played. It was a draw, therefore both players are losers!" << endl;
	}
	return success; //error code 0, means the program executed successfully

}

shared_ptr<GameBase> GameBase::pointer(int argc, char* argv[]) {
	if (argc != 0) {
		if ((string)argv[1] == "TicTacToe") {
			//TicTacToe ttt = TicTacToe();
			shared_ptr<GameBase> ttt = make_shared<TicTacToe>();
			return ttt;
		}
		else if ((string)argv[1] == "Gomoku") {
			shared_ptr<GameBase> gmk = make_shared<Gomoku>();
			return gmk;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}
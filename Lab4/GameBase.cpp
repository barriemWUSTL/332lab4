#include "GameBase.h"
#include "GamePiece.h"
#include "exitCodes.h"
#include <vector>
#include <iostream>
#include "TicTacToe.h"
#include "Gomoku.h"
#include <sstream>

using namespace std;


int GameBase::prompt(unsigned int& x, unsigned int& y) {
	std::vector<int> coords;
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

			std::stringstream ss(str);

			for (int i; ss >> i;) {
				coords.push_back(i);
				if (ss.peek() == ',' || ss.peek()==' ')
					ss.ignore();
			}
			if (coords.size() != coordLen) {
				cout << "Invalid coordinates, please reenter" << endl;
				return invalidCoordinates;
			}
			else if (name == "TicTacToe") {
				if (coords[coordFirst] >= 1 && coords[coordFirst] <= 3) {
					if (coords[coordSecond] >= 1 && coords[coordSecond] <= 3) {
						good = true;
					}
					else {
						cout << "Invalid coordinates, please reenter" << endl;
						return invalidCoordinates;
					}
				}
				else {
					cout << "Invalid coordinates, please reenter" << endl;
					return invalidCoordinates;
				}
			}
			else {
				if (coords[coordFirst] >= 1 && coords[coordFirst] <= 19) {
					if (coords[coordSecond] >= 1 && coords[coordSecond] <= 19) {
						good = true;
					}
					else {
						cout << "Invalid coordinates, please reenter" << endl;
						return invalidCoordinates;
					}
				}
				else {
					cout << "Invalid coordinates, please reenter" << endl;
					return invalidCoordinates;
				}

			}
			}
	}
		x = coords[coordFirst];
		y = coords[coordSecond];
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
// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "exitCodes.h"
#include "GameBoard.h"
using namespace std;
int usageMsg(char* str);

int main(int argc, char* argv[])
{
	string s = "TicTacToe";
	if (argc != indices::numberOfArgs) {
		return usageMsg(argv[indices::programName]);
	}

	else if (argv[indices::inputName] == s) {
		TicTacToe ttt;
		int gameState = ttt.play();
		return gameState;
	}
	else {
		return usageMsg(argv[indices::programName]);
	}
}

int usageMsg(char* str) {
	cout << "usage:" << str << " <game name (eg, TicTacToe)>" << endl;
	return wrongNumOfArgs;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

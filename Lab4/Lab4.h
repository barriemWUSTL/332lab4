#pragma once
#include <iostream>
#include <string>
#include "exitCodes.h"
#include "GameBase.h"

using namespace std;

int usageMsg(char* str) {
	std::cout << "usage:" << str << " <game name (eg, TicTacToe)>" << endl;
	return wrongNumOfArgs;
}

int usageMsg(int code) {
	std::cout << "Could not find that game. Please check the spelling of your input and try again." << endl;
	return wrongTypeOfGame;
}
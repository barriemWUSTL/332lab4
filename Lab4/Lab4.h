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
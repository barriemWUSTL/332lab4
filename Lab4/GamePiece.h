#pragma once
#include <string>
using namespace std;

struct GamePiece {
	string name;
	string icon;
};

struct Move {
	char Player;
	unsigned int x;
	unsigned int y;
};

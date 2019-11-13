#pragma once
#include <string>
using namespace std;

struct GamePiece {
	char name;
	string icon;
};

struct Move {
	GamePiece Player;
	unsigned int x;
	unsigned int y;
};

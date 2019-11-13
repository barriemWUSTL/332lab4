#pragma once
#include <vector>
#include <ostream>
#include "GamePiece.h"
using namespace std;
char switchPlayer(char player);

class GameBase {
	friend ostream &operator<<(ostream& cout, const GameBase& gb);
protected:
	vector<vector<string>> board;
	int height, length;
	string player;
	char playerid;
	int length;
	vector<Move> XMoves;
	vector<Move> OMoves;
public:
	GameBase();
	bool draw();
	bool done();
	int prompt(unsigned int& x, unsigned int& y);
	int turn();
	int play();
	GameBase gameType(int argc, char* argv[]);
};

class TicTacToe : public GameBase {

};
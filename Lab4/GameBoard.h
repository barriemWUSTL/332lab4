#pragma once
#include <vector>
#include <ostream>
#include "GamePiece.h"
using namespace std;
char switchPlayer(char player);

class GameBase {
	friend ostream &operator<<(ostream& cout, const GameBase& gb);
protected:
	vector<vector<char>> board;
	int height, length;
	char player;
	vector<Move> XMoves;
	vector<Move> OMoves;
public:
	GameBase();
	bool draw();
	bool done();
	int prompt(unsigned int& x, unsigned int& y);
	int turn();
	int play();
};

class TicTacToe : public GameBase {

};
#pragma once
#include <vector>
#include <ostream>
#include "GamePiece.h"
using namespace std;
//char switchPlayer(char player);
enum TicTacToePieces { pieceTurnIndex = 0, x = 'X', o = 'O', blank = ' ', b = 'B', w = 'W' };

class GameBase {
	//friend ostream &operator<<(ostream& cout, const GameBase& gb);
	//friend ostream& operator<<(ostream& cout, TicTacToe const& tt);
protected:
	vector<vector<string>> board;
	int height, length;
	int longestLength;
	string player;
	int lastRow;
	int lastCol;
	string lastPiece;
	vector<Move> XMoves;
	vector<Move> OMoves;
public:
	static GameBase* pointer(int argc, char* argv[]);
	virtual bool draw() = 0;
	virtual bool done() = 0;
	virtual int turn() = 0;
	virtual void print() = 0;
	int prompt(unsigned int& x, unsigned int& y);
	int play();
};

class TicTacToe : public GameBase {
	friend ostream& operator<<(ostream& cout, TicTacToe const& tt);
	TicTacToe();
public:
	void print() { cout << *this; }
	virtual bool done();
	virtual bool draw();
	virtual int turn();


private:
	string xValidMoves;
	string oValidMoves;

};

#pragma once
#include <vector>
#include <ostream>
#include "GamePiece.h"
#include "exitCodes.h"
#include <vector>
#include <iostream>
//#include "TicTacToe.h"
//#include "Gomoku.h"
#include<sstream>


using namespace std;
//char switchPlayer(char player);
enum TicTacToePieces { pieceTurnIndex = 0, x = 'X', o = 'O', blank = ' ', b='b', w='w'  };
template <typename Out>
void split(const std::string& s, char delim, Out result);
std::vector<std::string> split(const std::string& s, char delim);

class GameBase {
	//friend ostream &operator<<(ostream& cout, const GameBase& gb);
	//friend ostream& operator<<(ostream& cout, TicTacToe const& tt);

protected:
	vector<vector<string>> board;
	int height, length;
	size_t longestLength;
	string player;
	int lastRow;
	int lastCol;
	string lastPiece;
	int xDimensions; 
	int yDimensions;
	vector<Move> XMoves;
	vector<Move> OMoves;
public:
	string name;
	static shared_ptr<GameBase> pointer(int argc, char* argv[]);
	virtual bool draw() = 0;
	virtual bool done() = 0;
	virtual int turn() = 0;
	virtual void print() = 0;
	virtual int prompt(unsigned int& x, unsigned int& y);
	int play();
};
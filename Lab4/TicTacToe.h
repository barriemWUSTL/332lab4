#pragma once
#include "GameBase.h"
#include <iostream>
#include "exitCodes.h"

class TicTacToe : public GameBase {
	friend ostream& operator<<(ostream& cout, TicTacToe const& tt);

public:
	TicTacToe();
	void print() { std::cout << *this; }
	virtual bool done();
	virtual bool draw();
	virtual int turn();


private:
	string xValidMoves;
	string oValidMoves;

};

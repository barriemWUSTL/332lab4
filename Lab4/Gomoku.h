#pragma once
#include "GameBase.h"
#include <iostream>
#include "exitCodes.h"

using namespace std;


class Gomoku : public GameBase {
	friend ostream& operator<<(ostream& cout, Gomoku const& tt);
public:
	Gomoku();
	void print() { std::cout << *this; }
	//virtual bool done();
	//virtual bool draw();
	//virtual int turn();


private:
	string xValidMoves;
	string oValidMoves;

};



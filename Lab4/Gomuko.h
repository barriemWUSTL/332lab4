#include "GameBase.h";
#include <iostream>
#include "exitCodes.h"

using namespace std;


class Gomuku : public GameBase {
	friend ostream& operator<<(ostream& cout, Gomuku const& tt);

public:
	Gomuku();
	void print() { std::cout << *this; }
	virtual bool done();
	virtual bool draw();
	virtual int turn();


private:
	string xValidMoves;
	string oValidMoves;

};



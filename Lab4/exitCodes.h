#pragma once
enum exits {
	success = 0,
	quit = 1,
	draw = 2,
	wrongNumOfArgs = 3,
	somethingWentWrong = 4,
	allocationFail = 5,
	wrongTypeOfGame = 6,
	invalidCoordinates = 7
};

enum coordIndices {
	coordLen = 2,
	coordFirst = 0,
	coordSecond = 1
};

enum boardSize {
	boardLen = 5,
	boardHeight = 5,
	gBoardLen = 19,
	gBoardHeight = 19
};

enum indices {
	programName = 0,
	inputName = 1,
	numberOfArgs = 2
};
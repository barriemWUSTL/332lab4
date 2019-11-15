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
	coordLen = 3,
	coordFirst = 0,
	coordComma = 1,
	coordSecond = 2
};

enum boardSize {
	boardLen = 5,
	boardHeight = 5
};

enum indices {
	programName = 0,
	inputName = 1,
	numberOfArgs = 2
};
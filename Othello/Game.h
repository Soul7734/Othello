#pragma once
#include "Board.h"

// Game commands
class Game
{
private:
	bool turnSwitch;
	bool isPvp;
	string xCoord;
	string yCoord;
public:
	Game();
	bool getTurnSwitch();
	void flipTurn();
	bool getIsPvp();
	void setIsPvp(bool pvpMode);
	string getXCoord();
	void setXCoord();
	string getYCoord();
	void setYCoord();
	void playGame(Board& board);
	void playGameAI(Board& board);
	bool validateString(string text);
	void clear();
};
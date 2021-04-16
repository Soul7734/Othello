#pragma once
#include <string>
#include "Board.h"

// Game commands
class Game
{
private:
	bool turnSwitch;
	bool isPvp;
	std::string xCoord;
	std::string yCoord;
public:
	Game();
	bool getTurnSwitch();
	void flipTurn();
	bool getIsPvp();
	void setIsPvp(bool pvpMode);
	std::string getXCoord();
	void setXCoord();
	std::string getYCoord();
	void setYCoord();
	void playGame(Board& board);
	void playGameAI(Board& board);
	bool validateString(std::string text);
	void clear();
};
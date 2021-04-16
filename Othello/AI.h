#pragma once
#include "Board.h"

// AI commands
	class AI
	{
	private:
		int x;
		int y;
	public:
		AI();
		int randINT();
		void setX(int X);
		void setY(int Y);
		int getX();
		int getY();
		void EasyMode();
		void NormalMode();
		void HardMode();
		void determineBoard(Board& board);
	};
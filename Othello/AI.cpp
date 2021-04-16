#include <cstdlib>
#include "AI.h"
#include "Player.cpp"

using namespace ai;

	Player player;
	Board GameBoard;

	int AI::randINT()
	{
		int randomNumber;
		for (int index = 0; index < 7; index++)
		{
			randomNumber = (rand() % 8) + 1;
		}

		return randomNumber;
	}


	AI::AI()
	{
		x = 0;
		y = 0;
	}

	void AI::setX(int X)
	{
		this->x = X;
	}

	void AI::setY(int Y)
	{
		this->y = Y;
	}

	int AI::getX()
	{
		return x;
	}

	int AI::getY()
	{
		return y;
	}

	void AI::EasyMode()
	{
		setX(randINT());
		setY(randINT());
	}

	void AI::NormalMode()
	{

	}

	void AI::HardMode()
	{

	}

	void AI::determineBoard(Board& map)
	{
		bool possibleFlips[8] = { false, false, false, false, false, false, false, false };
		int* possibleCoord = new int[8 * 8];
		int n = 0;

		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				if (GameBoard.isTileEmpty(GameBoard.getCurrentBoard(), x, y) == true)
				{
					if (GameBoard.adjacent_N(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
					{
						if (GameBoard.inline_N(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
						{
							possibleFlips[0] = true;
							n += 1;
						}
					}
					if (GameBoard.adjacent_NE(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
					{
						if (GameBoard.inline_NE(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
						{
							possibleFlips[1] = true;
							n += 1;
						}
					}
					if (GameBoard.adjacent_E(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
					{
						if (GameBoard.inline_E(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
						{
							possibleFlips[2] = true;
							n += 1;
						}
					}
					if (GameBoard.adjacent_SE(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
					{
						if (GameBoard.inline_SE(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
						{
							possibleFlips[3] = true;
							n += 1;
						}
					}
					if (GameBoard.adjacent_S(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
					{
						if (GameBoard.inline_S(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
						{
							possibleFlips[4] = true;
							n += 1;
						}
					}
					if (GameBoard.adjacent_SW(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
					{
						if (GameBoard.inline_SW(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
						{
							possibleFlips[5] = true;
							n += 1;
						}
					}
					if (GameBoard.adjacent_W(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
					{
						if (GameBoard.inline_W(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
						{
							possibleFlips[6] = true;
							n += 1;
						}
					}
					if (GameBoard.adjacent_NW(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
					{
						if (GameBoard.inline_NW(GameBoard.getCurrentBoard(), player.getPlayer2(), x, y) == true)
						{
							possibleFlips[7] = true;
							n += 1;
						}
					}

					if (n != sizeof(possibleFlips))
					{

					}
				}
			}
		}
	}
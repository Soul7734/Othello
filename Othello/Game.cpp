
#include <iostream>
#include <regex>
#include <stdlib.h>

#include "Player.h"
#include "AI.h"
#include "Game.h"

using namespace std;

Player player;
AI ai;
	
	Game::Game()
	{
		turnSwitch = true;
		isPvp = true;
		xCoord = "";
		yCoord = "";
	}

	bool Game::getTurnSwitch()
	{
		return turnSwitch;
	}

	void Game::flipTurn()
	{
		turnSwitch = !turnSwitch;
	}

	bool Game::getIsPvp()
	{
		return isPvp;
	}

	void Game::setIsPvp(bool pvpMode)
	{
		this->isPvp = pvpMode;
	}

	string Game::getXCoord()
	{
		return xCoord;
	}

	void Game::setXCoord()
	{
		cin >> this->xCoord;
	}

	string Game::getYCoord()
	{
		return yCoord;
	}

	void Game::setYCoord()
	{
		cin >> this->yCoord;
	}

	void Game::playGame(Board& board)
	{
		while (true)
		{
			while (true)
			{
				if (getTurnSwitch() == true)
				{
					cout << "Black X: ";
					setXCoord();

					cout << "Black Y: ";
					setYCoord();
				}
				else
				{
					cout << "White X: ";
					setXCoord();

					cout << "White Y: ";
					setYCoord();
				}
				if (getTurnSwitch() == true)
				{
					if (validateString(getXCoord()) == true && validateString(getYCoord()) == true)
					{
						cout << "Black's Move - X: " << getXCoord() << ", Y: " << getYCoord() << endl;

						if (board.isTileEmpty(board.getCurrentBoard(), stoi(getXCoord()), stoi(getYCoord())) == true)
						{
							clear();
							board.determineAndFlip(board.getCurrentBoard(), player.getPlayer1(), stoi(getXCoord()), stoi(getYCoord()));
							board.printBoard(board.getCurrentBoard());
							flipTurn();
							break;
						}
					}
				}
				else
				{
					if (validateString(getXCoord()) == true && validateString(getYCoord()) == true)
					{
						cout << "White's Move - X: " << getXCoord() << ", Y: " << getYCoord() << endl;
					}
					if (board.isTileEmpty(board.getCurrentBoard(), stoi(getXCoord()), stoi(getYCoord())) == true)
					{
						clear();
						board.determineAndFlip(board.getCurrentBoard(), player.getPlayer2(), stoi(getXCoord()), stoi(getYCoord()));
						board.printBoard(board.getCurrentBoard());
						flipTurn();
						break;
					}
				}
			}
		}
	}

	void Game::playGameAI(Board& board)
	{
		while (true)
		{
			while (true)
			{
				if (getTurnSwitch() == true)
				{
					cout << "Black X: ";
					setXCoord();

					cout << "Black Y: ";
					setYCoord();
				}
				else
				{
					ai.EasyMode();
				}

				if (getTurnSwitch() == true)
				{
					if (validateString(getXCoord()) == true && validateString(getYCoord()) == true)
					{
						cout << "Black's Move - X: " << getXCoord() << ", Y: " << getYCoord() << endl;

						if (board.isTileEmpty(board.getCurrentBoard(), stoi(getXCoord()), stoi(getYCoord())) == true)
						{
							//clear();
							board.determineAndFlip(board.getCurrentBoard(), player.getPlayer1(), stoi(getXCoord()), stoi(getYCoord()));
							board.printBoard(board.getCurrentBoard());
							flipTurn();
							break;
						}
					}
				}
				else
				{
					cout << "White's Move - X: " << ai.getX() << ", Y: " << ai.getY() << endl;

					if (board.isTileEmpty(board.getCurrentBoard(), ai.getX(), ai.getY()) == true)
					{
						//clear();
						board.determineAndFlip(board.getCurrentBoard(), player.getPlayer2(), ai.getX(), ai.getY());
						board.printBoard(board.getCurrentBoard());
						flipTurn();
						break;
					}
				}
			}
		}
	}

	bool Game::validateString(string text)
	{
		regex n("[0-7]");
		return regex_match(text, n);
	}

	void Game::clear()
	{
		system("CLS");
	}
	
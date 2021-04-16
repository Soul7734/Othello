#pragma once
#include <iostream>
#include <stdlib.h>

#include "Game.cpp"
#include "Board.cpp"
#include "Menu.h"
using namespace std;
using namespace menu;

Game game;
Board board;

void Menu::mainMenu()
{
	cout << "==========================================================" << endl;
	cout << "\t\tOthello/Reversi - C++ Edition" << endl;
	cout << "==========================================================" << endl;
	cout << "\nPlease choose one of the following options by \nentering the number assigned to the option \nand pressing ENTER." << endl;
	cout << "\n\t1. - Play Game" << endl;
	cout << "\t2. - Load Game" << endl;
	cout << "\t3. - Exit Game" << endl;
	cout << "\n==========================================================\n" << endl;
}

	void Menu::WhichGM()
	{
		cout << "\t1. - Local Co-op 2 Player" << endl;
		cout << "\t2. - Player vs AI" << endl;
	}

	void Menu::determineUserChoice()
	{
		string user;
		string user2;
		while (true)
		{
			game.clear();
			mainMenu();
			cout << "User: ";
			cin >> user;

			if (game.validateString(user) == true)
			{
				if (user == "1")
				{
					game.clear();
					WhichGM();
					while (true)
					{
						cout << "\nUser: ";
						cin >> user2;

						if (game.validateString(user2) == true)
						{
							if (user2 == "1")
							{
								board.setDefaultBoard();
								board.printBoard(board.getCurrentBoard());

								game.playGame(board);
								break;
							}
							else if (user2 == "2")
							{
								board.setDefaultBoard();
								board.printBoard(board.getCurrentBoard());

								game.playGameAI(board);
								break;
								break;
							}
							else
							{
								continue;
							}
						}
					}
				}
				else if (user == "2")
				{
					break;
				}
				else if (user == "3")
				{
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
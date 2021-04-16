#pragma once

// Board commands
namespace board
{
	class Board
	{
	private:
		int* currentBoard;

	public:
		Board();
		void setDefaultBoard();
		void updateBoard(int* board);
		int* getCurrentBoard();
		void printBoard(int* board);
		bool isTileEmpty(int* board, int x, int y);
		void placePiece(int color, int x, int y);
		void determineAndFlip(int* board, int color, int x, int y);
		bool adjacent_N(int* board, int color, int x, int y);
		bool adjacent_E(int* board, int color, int x, int y);
		bool adjacent_S(int* board, int color, int x, int y);
		bool adjacent_W(int* board, int color, int x, int y);
		bool adjacent_NE(int* board, int color, int x, int y);
		bool adjacent_SE(int* board, int color, int x, int y);
		bool adjacent_SW(int* board, int color, int x, int y);
		bool adjacent_NW(int* board, int color, int x, int y);
		bool inline_N(int* board, int color, int x, int y);
		bool inline_E(int* board, int color, int x, int y);
		bool inline_S(int* board, int color, int x, int y);
		bool inline_W(int* board, int color, int x, int y);
		bool inline_NE(int* board, int color, int x, int y);
		bool inline_SE(int* board, int color, int x, int y);
		bool inline_SW(int* board, int color, int x, int y);
		bool inline_NW(int* board, int color, int x, int y);
		void flip_N(int* board, int color, int x, int y);
		void flip_NE(int* board, int color, int x, int y);
		void flip_E(int* board, int color, int x, int y);
		void flip_SE(int* board, int color, int x, int y);
		void flip_S(int* board, int color, int x, int y);
		void flip_SW(int* board, int color, int x, int y);
		void flip_W(int* board, int color, int x, int y);
		void flip_NW(int* board, int color, int x, int y);
		int oppositePlayer(int color);
	};
}
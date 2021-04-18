
#include <iostream>

#include "Board.h"

using namespace std;

    Board::Board()
    {
        currentBoard = new int[8 * 8];
    }

    void Board::setDefaultBoard()
    {
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (x == 3 && y == 4)
                {
                    currentBoard[x + y * 8] = 2;
                }
                else if (x == 4 && y == 3)
                {
                    currentBoard[x + y * 8] = 2;
                }
                else if (x == 4 && y == 4)
                {
                    currentBoard[x + y * 8] = 1;
                }
                else if (x == 3 && y == 3)
                {
                    currentBoard[x + y * 8] = 1;
                }
                else
                {
                    currentBoard[x + y * 8] = 0;
                }
            }
        }
    }

    void Board::updateBoard(int* board)
    {
        this->currentBoard = board;
    }

    int* Board::getCurrentBoard()
    {
        return currentBoard;
    }

    void Board::printBoard(int* board)
    {
        cout << " |0    1    2    3    4    5    6    7" << endl;
        cout << "=|=====================================" << endl;
        for (int y = 0; y < 8; y++)
        {
            cout << " |" << "\n" << y << "|";
            for (int x = 0; x < 8; x++)
            {
                cout << board[x + y * 8] << "    ";
            }
            cout << endl;
        }
    }

    bool Board::isTileEmpty(int* board, int x, int y)
    {
        if (board[x + y * 8] == 1 || board[x + y * 8] == 2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void Board::placePiece(int color, int x, int y)
    {
        int* board = getCurrentBoard();

        board[x + y * 8] = color;

        updateBoard(board);
    }

    void Board::determineAndFlip(int* board, int color, int x, int y)
    {
        bool determinant[8] = { false, false, false, false, false, false, false, false };

        if (adjacent_N(getCurrentBoard(), color, x, y))
        {
            if (inline_N(board, color, x, y) == true)
            {
                flip_N(board, color, x, y);
                determinant[0] = true;
            }
        }

        if (adjacent_E(board, color, x, y) == true)
        {
            if (inline_E(board, color, x, y) == true)
            {
                flip_E(board, color, x, y);
                determinant[2] = true;
            }
        }

        if (adjacent_S(board, color, x, y) == true)
        {
            if (inline_S(board, color, x, y) == true)
            {
                flip_S(board, color, x, y);
                determinant[4] = true;
            }
        }

        if (adjacent_W(board, color, x, y) == true)
        {
            if (inline_W(board, color, x, y) == true)
            {
                flip_W(board, color, x, y);
                determinant[6] = true;
            }
        }

        if (adjacent_NE(board, color, x, y) == true)
        {
            if (inline_NE(board, color, x, y) == true)
            {
                flip_NE(board, color, x, y);
                determinant[1] = true;
            }
        }

        if (adjacent_SE(board, color, x, y) == true)
        {
            if (inline_SE(board, color, x, y) == true)
            {
                flip_SE(board, color, x, y);
                determinant[3] = true;
            }
        }

        if (adjacent_SW(board, color, x, y) == true)
        {
            if (inline_SW(board, color, x, y) == true)
            {
                flip_SW(board, color, x, y);
                determinant[5] = true;
            }
        }

        if (adjacent_NW(board, color, x, y) == true)
        {
            if (inline_NW(board, color, x, y) == true)
            {
                flip_NW(board, color, x, y);
                determinant[7] = true;
            }
        }

        int n = 0;

        for (int i = 0; i < sizeof(determinant); i++)
        {
            if (determinant[i] == false)
            {
                n += 1;
            }
        }

        if (n != sizeof(determinant))
        {
            placePiece(color, x, y);
        }
    }

    bool Board::adjacent_N(int* board, int color, int x, int y)
    {
        int newY = y - 1;

        if (board[x + newY * 8] == oppositePlayer(color))
        {
            return true;
        }
        else if (board[x + newY * 8] == color)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool Board::adjacent_E(int* board, int color, int x, int y)
    {
        int newX = x + 1;

        if (board[newX + y * 8] == oppositePlayer(color))
        {
            return true;
        }
        else if (board[newX + y * 8] == color)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool Board::adjacent_S(int* board, int color, int x, int y)
    {
        int newY = y + 1;

        if (board[x + newY * 8] == oppositePlayer(color))
        {
            return true;
        }
        else if (board[x + newY * 8] == color)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool Board::adjacent_W(int* board, int color, int x, int y)
    {
        int newX = x - 1;

        if (board[newX + y * 8] == oppositePlayer(color))
        {
            return true;
        }
        else if (board[newX + y * 8] == color)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool Board::adjacent_NE(int* board, int color, int x, int y)
    {
        int newY = y - 1;
        int newX = x + 1;

        if (board[newX + newY * 8] == oppositePlayer(color))
        {
            return true;
        }
        else if (board[newX + newY * 8] == color)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool Board::adjacent_SE(int* board, int color, int x, int y)
    {
        int newY = y + 1;
        int newX = x + 1;

        if (board[newX + newY * 8] == oppositePlayer(color))
        {
            return true;
        }
        else if (board[newX + newY * 8] == color)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool Board::adjacent_SW(int* board, int color, int x, int y)
    {
        int newY = y + 1;
        int newX = x - 1;

        if (board[newX + newY * 8] == oppositePlayer(color))
        {
            return true;
        }
        else if (board[newX + newY * 8] == color)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool Board::adjacent_NW(int* board, int color, int x, int y)
    {
        int newY = y - 1;
        int newX = x - 1;

        if (board[newX + newY * 8] == oppositePlayer(color))
        {
            return true;
        }
        else if (board[newX + newY * 8] == color)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool Board::inline_N(int* board, int color, int x, int y)
    {
        for (int i = y; i > -1; i--)
        {
            if (board[x + i * 8] == color)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }

    bool Board::inline_E(int* board, int color, int x, int y)
    {
        for (int i = x; i < 8; i++)
        {
            if (board[i + y * 8] == color)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }

    bool Board::inline_S(int* board, int color, int x, int y)
    {
        for (int i = y; i < 8; i++)
        {
            if (board[x + i * 8] == color)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }

    bool Board::inline_W(int* board, int color, int x, int y)
    {
        for (int i = x; i > -1; i--)
        {
            if (board[i + y * 8] == color)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }

    bool Board::inline_NE(int* board, int color, int x, int y)
    {
        for (int i = 0; i < 8; i++)
        {
            int newX = x + i;
            int newY = y - i;

            if (newX > 7 || newY < 0)
            {
                break;
            }

            if (board[newX + newY * 8] == color)
            {
                return true;
            }
            else
            {
                continue;
            }

        }
        return false;
    }

    bool Board::inline_SE(int* board, int color, int x, int y)
    {
        for (int i = 0; i < 8; i++)
        {
            int newX = x + i;
            int newY = y + i;

            if (newX > 7 || newY > 7)
            {
                break;
            }

            if (board[newX + newY * 8] == color)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }

    bool Board::inline_SW(int* board, int color, int x, int y)
    {
        for (int i = 0; i < 8; i++)
        {
            int newX = x - i;
            int newY = y + i;

            if (newX < 0 || newY > 7)
            {
                break;
            }

            if (board[newX + newY * 8] == color)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }

    bool Board::inline_NW(int* board, int color, int x, int y)
    {
        for (int i = 0; i < 8; i++)
        {
            int newX = x - i;
            int newY = y - i;

            if (newX < 0 || newY < 0)
            {
                break;
            }

            if (board[newX + newY * 8] == color)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }

    int Board::oppositePlayer(int color)
    {
        if (color == 1)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }

    void Board::flip_N(int* board, int color, int x, int y)
    {
        for (int i = y - 1; i > -1; i--)
        {
            if (board[x + i * 8] == oppositePlayer(color))
            {
                board[x + i * 8] = color;
            }
            else if (board[x + i * 8] == color)
            {
                break;
            }
        }
        updateBoard(board);
    }

    void Board::flip_E(int* board, int color, int x, int y)
    {
        for (int i = x + 1; i < 8; i++)
        {
            if (board[i + y * 8] == oppositePlayer(color))
            {
                board[i + y * 8] = color;
            }
            else if (board[i + y * 8] == color)
            {
                break;
            }
        }
        updateBoard(board);
    }

    void Board::flip_S(int* board, int color, int x, int y)
    {
        for (int i = y + 1; i < 8; i++)
        {
            if (board[x + i * 8] == oppositePlayer(color))
            {
                board[x + i * 8] = color;
            }
            else if (board[x + i * 8] == color)
            {
                break;
            }
        }
        updateBoard(board);
    }

    void Board::flip_W(int* board, int color, int x, int y)
    {
        for (int i = x - 1; i > -1; i--)
        {
            if (board[i + y * 8] == oppositePlayer(color))
            {
                board[i + y * 8] = color;
            }
            else if (board[i + y * 8] == color)
            {
                break;
            }
        }
        updateBoard(board);
    }

    void Board::flip_NE(int* board, int color, int x, int y)
    {
        int newX = x + 1;
        int newY = y - 1;

        for (int i = 0; i < 8; i++)
        {
            newX += i;
            newY -= i;

            if (newX > 7 || newY < 0)
            {
                break;
            }

            if (board[newX + newY * 8] == oppositePlayer(color))
            {
                cout << "FLIP!" << endl;
                board[newX + newY * 8] = color;
            }
            else if (board[newX + newY * 8] == color)
            {
                cout << "breaking" << endl;
                break;
            }
        }
        updateBoard(board);
    }

    void Board::flip_SE(int* board, int color, int x, int y)
    {
        int newX = x + 1;
        int newY = y + 1;

        for (int i = 0; i < 8; i++)
        {
            newX += i;
            newY += i;

            if (newX > 7 || newY > 7)
            {
                break;
            }

            if (board[newX + newY * 8] == oppositePlayer(color))
            {
                board[newX + newY * 8] = color;
            }
            else if (board[newX + newY * 8] == color)
            {
                break;
            }
        }
        updateBoard(board);
    }

    void Board::flip_SW(int* board, int color, int x, int y)
    {
        int newX = x - 1;
        int newY = y + 1;

        for (int i = 0; i < 8; i++)
        {
            newX -= i;
            newY += i;

            if (newX < 0 || newY > 7)
            {
                break;
            }

            if (board[newX + newY * 8] == oppositePlayer(color))
            {
                board[newX + newY * 8] = color;
            }
            else if (board[newX + newY * 8] == color)
            {
                break;
            }
        }
        updateBoard(board);
    }

    void Board::flip_NW(int* board, int color, int x, int y)
    {
        int newX = x - 1;
        int newY = y - 1;

        for (int i = 0; i < 8; i++)
        {
            newX -= i;
            newY -= i;

            if (newX < 0 || newY < 0)
            {
                break;
            }

            if (board[newX + newY * 8] == oppositePlayer(color))
            {
                board[newX + newY * 8] = color;
            }
            else if (board[newX + newY * 8] == color) {
                break;
            }
        }
        updateBoard(board);
    }


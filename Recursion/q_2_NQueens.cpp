#include <bits/stdc++.h>
using namespace std;

void saveBoard(vector<vector<char>> &board, vector<vector<string>> &allBoards)
{
    vector<string> newBoard;
    for (int i = 0; i < board.size(); i++)
    {
        string row = "";
        for (int j = 0; j < board.size(); j++)
        {
            row += board[i][j];
        }
        newBoard.push_back(row);
    }
    allBoards.push_back(newBoard);
}
bool isSafe(int row, int col, vector<vector<char>> &board)
{
    int currRow = row;
    int currCol = col;

    // horizontal check
    while (currCol >= 0)
    {
        if (board[currRow][currCol] == 'Q')
        {
            return false;
        }
        currCol--;
    }

    // upper-left diagonal
    currRow = row;
    currCol = col;
    while (currRow >= 0 && currCol >= 0)
    {
        if (board[currRow][currCol] == 'Q')
        {
            return false;
        }
        currRow--;
        currCol--;
    }

    // upper-right diagonal
    currRow = row;
    currCol = col;
    while (currRow >= 0 && currCol < board.size())
    {
        if (board[currRow][currCol] == 'Q')
        {
            return false;
        }
        currRow--;
        currCol++;
    }

    // lower-left diagonal
    currRow = row;
    currCol = col;
    while (currRow < board.size() && currCol >= 0)
    {
        if (board[currRow][currCol] == 'Q')
        {
            return false;
        }
        currRow++;
        currCol--;
    }

    // lower-right diagonal
    currRow = row;
    currCol = col;
    while (currRow < board.size() && currCol < board.size())
    {
        if (board[currRow][currCol] == 'Q')
        {
            return false;
        }
        currRow++;
        currCol++;
    }

    return true;
}
void solve(int col, int n, vector<vector<char>> &board, vector<vector<string>> &allBoards)
{
    if (col == board.size())
    {
        saveBoard(board, allBoards);
        return;
    }
    for (int row = 0; row < board.size(); row++)
    {
        if (isSafe(row, col, board) == true)
        {
            board[row][col] = 'Q';
            solve(col + 1, n - 1, board, allBoards);
            board[row][col] = '.';
        }
    }
    return;
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> allBoards;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    solve(0, n, board, allBoards);
    return allBoards;
}
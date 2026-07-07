#include <iostream>
#include <vector>
using namespace std;

int countSolutions = 0; // Added global counter

bool issafe(vector<vector<char>> &board, int r, int c)
{
    int n = board.size();
    // vertical
    for (int i = 0; i < r; i++)
    {
        if ('Q' == board[i][c])
        {
            return false;
        }
    }

    // left diag
    for (int i = r, j = c; i >= 0 && j >= 0; j--, i--)
    {
        if ('Q' == board[i][j])
        {
            return false;
        }
    }

    // right diag
    for (int i = r, j = c; i >= 0 && j < n; j++, i--)
    {
        if ('Q' == board[i][j])
        {
            return false;
        }
    }

    return true;
}

void print(vector<vector<char>> board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void nQueens(int r, int n, vector<vector<char>> &board)
{
    if (r == n)
    {
        print(board);
        countSolutions++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (issafe(board, r, i))
        {
            board[r][i] = 'Q';
            nQueens(r + 1, n, board);
            board[r][i] = '.';
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<char>> board(n, vector<char>(n, '.'));

    nQueens(0, n, board);

    cout << "Total Solutions: " << countSolutions << endl;

    return 0;
}
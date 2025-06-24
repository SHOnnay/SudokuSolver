#include <iostream>
#include <string>
#include <vector>

using namespace std;

//printing the solution
void printSudoku(int sudoku[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}


//check if safe
bool isSafe(int sudoku[][9], int row, int col, int digit)
{
    // vertical
    for (int i = 0; i <= 8; i++)
    {
        if (sudoku[i][col] == digit)
        {
            return false;
        }
    }

    // horizontal
    for (int j = 0; j <= 8; j++)
    {
        if (sudoku[row][j] == digit)
        {
            return false;
        }
    }

    // 3X3 grid
    int srow = (row / 3) * 3, scol = (col / 3) * 3;

    for (int i = srow; i <= srow + 2; i++)
    {
        for (int j = scol; j <= scol + 2; j++)
        {
            if (sudoku[i][j] == digit)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int sudoku[][9], int row, int col)
{
    if (row == 9)
    {
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (sudoku[row][col] != 0)
    {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }
    for (int digit = 1; digit <= 9; digit++)
    {
        if (isSafe(sudoku, row, col, digit))
        {
            sudoku[row][col] = digit;
            if (sudokuSolver(sudoku, nextRow, nextCol))
            {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }

    return false;
}

//user input
void input(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }
}


int main()
{
    int sudoku[9][9];
    input(sudoku);
    sudokuSolver(sudoku, 0, 0);

    return 0;
}

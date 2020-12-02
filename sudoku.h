#pragma once

class sudoku
{
    static const int m = 9;
protected:
    int sudokmatrix[m][m];
    bool findEmptySlot(int& row, int& col);
    bool canPlaceNum(int row, int col, int num);
    bool numAlreadyInRow(int row, int num);
    bool numAlreadyInCol(int col, int num);
    bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);
public:
    sudoku();
    ~sudoku() {};
    void enterDigits();
    void print();
    bool solve();
};


sudoku::sudoku() : sudokmatrix{}
{
    std::cout << "\nMatrix initialized \n\n";
}

void sudoku::enterDigits()
{
    for (int i{}; i < 9; i++)
        for (int j{}; j < 9; j++)
            std::cin >> sudokmatrix[i][j];
}

bool sudoku::findEmptySlot(int& row, int& col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (sudokmatrix[row][col] == 0)
                return true;
        }
    }
    return false;
}

void sudoku::print()
{
    std::cout << "\n";
    for (int i{}; i < 9; i++) {
        for (int j{}; j < 9; j++)
            std::cout << sudokmatrix[i][j] << " ";
        std::cout << "\n";
    }
}

bool sudoku::numAlreadyInRow(int row, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (num != 0 && sudokmatrix[row][i] == num)
            return true;
    }
    return false;
}

bool sudoku::numAlreadyInCol(int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (num != 0 && sudokmatrix[i][col] == num)
            return true;
    }
    return false;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudokmatrix[i + smallGridRow][j + smallGridCol] == num)
                return true;
        }
    }
    return false;
}

bool sudoku::canPlaceNum(int row, int col, int num)
{
    if (!numAlreadyInRow(row, num))
    {
        if (!numAlreadyInCol(col, num))
        {
            int smallGridRow = (row / 3) * 3;
            int smallGridCol = (col / 3) * 3;
            if (!numAlreadyInBox(smallGridRow, smallGridCol, num))
            {
                return true;
            }
        }
    }
    return false;
}

bool sudoku::solve()
{
    int row, col;
    if (findEmptySlot(row, col))
    {
        for (int num = 1; num <= 9; num++)
        {
            if (canPlaceNum(row, col, num))
            {
                sudokmatrix[row][col] = num;
                if (solve())
                    return true;
                sudokmatrix[row][col] = 0;
            }
        }
        return false;
    }
    else
        return true;
}

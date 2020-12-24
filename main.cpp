#include <iostream>
#include <vector>
#include <algorithm>
#include "sudoku.h"


int main()
{
    sudoku s;
    s.enterDigits();
    if (s.solve())
        s.print();
    else
        std::cout << "\n Solution doesnt exist \n";
    return 0;
}

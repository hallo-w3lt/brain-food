/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>
#include <set>

// Write a function validSolution/ValidateSolution/valid_solution() that accepts a 2D array representing a Sudoku board,
// and returns true if it is a valid solution, or false otherwise. The cells of the sudoku board may also contain 0's,
// which will represent empty cells. Boards containing one or more zeroes are considered to be invalid solutions.

// The board is always 9 cells by 9 cells, and every cell only contains integers from 0 to 9.

// validSolution([
//   [5, 3, 4, 6, 7, 8, 9, 1, 2],
//   [6, 7, 2, 1, 9, 5, 3, 4, 8],
//   [1, 9, 8, 3, 4, 2, 5, 6, 7],
//   [8, 5, 9, 7, 6, 1, 4, 2, 3],
//   [4, 2, 6, 8, 5, 3, 7, 9, 1],
//   [7, 1, 3, 9, 2, 4, 8, 5, 6],
//   [9, 6, 1, 5, 3, 7, 2, 8, 4],
//   [2, 8, 7, 4, 1, 9, 6, 3, 5],
//   [3, 4, 5, 2, 8, 6, 1, 7, 9]
// ]); // => true

// validSolution([
//   [5, 3, 4, 6, 7, 8, 9, 1, 2],
//   [6, 7, 2, 1, 9, 0, 3, 4, 8],
//   [1, 0, 0, 3, 4, 2, 5, 6, 0],
//   [8, 5, 9, 7, 6, 1, 0, 2, 0],
//   [4, 2, 6, 8, 5, 3, 7, 9, 1],
//   [7, 1, 3, 9, 2, 4, 8, 5, 6],
//   [9, 0, 1, 5, 3, 7, 2, 1, 4],
//   [2, 8, 7, 4, 1, 9, 6, 3, 5],
//   [3, 0, 0, 4, 8, 1, 1, 7, 9]
// ]); // => false

bool solution(unsigned int const board[9][9])
{
    auto check
    {
        [](std::set<int> &source)
        {
            return 9 == source.size() &&
                   0 == std::count(source.begin(), source.end(), 0) &&
                   45 == std::accumulate(source.begin(), source.end(), 0);
        }
    };

    auto check_matrix
    {
        [&]()
        {
            std::vector<int> cube{0,0,0};
            for (int x {0}; x < 9; ++x)
            {
                std::set<int> row {};
                std::set<int> column {};

                for (int y {0}; y < 9; ++y)
                {
                    row.insert(board[x][y]);
                    column.insert(board[y][x]);
                    cube.at(y/3) += board[x][y];
                }

                if (!check(row) || !check(column)) {return false;}

                if (0 == (x+1) % 3)
                {
                    if (std::vector<int>{45,45,45} != cube) { return false; }
                    cube = {0,0,0};
                }
            }

            return true;
        }
    };

    return check_matrix();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

# if 0
    unsigned int const source[9][9] {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8}
    };
#endif

# if 1
    unsigned int const source[9][9] {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
#endif

# if 0
    unsigned int source[9][9] {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 0, 3, 4, 8},
        {1, 0, 0, 3, 4, 2, 5, 6, 0},
        {8, 5, 9, 7, 6, 1, 0, 2, 0},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 0, 1, 5, 3, 7, 2, 1, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 0, 0, 4, 8, 1, 1, 7, 9}
    };
#endif

    std::cout << "solution: " << std::boolalpha << solution(source) << std::endl;

    return a.exec();
}

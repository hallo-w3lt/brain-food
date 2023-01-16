/*
* Copyright (c) 2023 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>
#include <vector>

// Given an n x n array, return the array elements arranged from outermost elements to the middle element,
// traveling clockwise.

// array = [[1,2,3],
//          [4,5,6],
//          [7,8,9]]
// snail(array) #=> [1,2,3,6,9,8,7,4,5]

// For better understanding, please follow the numbers of the next array consecutively:

// array = [[1,2,3],
//          [8,9,4],
//          [7,6,5]]
// snail(array) #=> [1,2,3,4,5,6,7,8,9]

// NOTE: The idea is not sort the elements from the lowest value to the highest;
// the idea is to traverse the 2-d array in a clockwise snailshell pattern.
//
// NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
//

std::ostream& operator<<(std::ostream& os, std::vector<int> const& source)
{
    size_t const size {source.size()};
    os << "[";

    for (int i {0}; i < size; ++i)
    {
        os << source[i];
        if ( i != size - 1)
        {
            os << ", ";
        }
    }

    os << "]";
    return os;
}

std::vector<int> snail(std::vector<std::vector<int>> const& snail_map)
{
    std::vector<int> result {};
    size_t rows {snail_map.size()};
    size_t columns {snail_map[0].size()};

    if (0 == rows || 0 == columns) {return result;}

    int x {0}, y {0};

    while (x < rows && y < columns)
    {
        // top
        for (int i = y; i < columns; ++i)
        {
            result.push_back(snail_map[x][i]);
        }
        x++;

        // right
        for (int i = x; i < rows; ++i)
        {
            result.push_back(snail_map[i][columns-1]);
        }
        columns--;

        // down
        if (x < rows)
        {
            for (int i = columns-1; i >= y; --i)
            {
                result.push_back(snail_map[rows-1][i]);
            }
            rows--;
        }

        // left
        if (y < columns)
        {
            for (int i = rows-1; i >= x; --i)
            {
                result.push_back(snail_map[i][y]);
            }
            y++;
        }

    }

    return result;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // const std::vector<std::vector<int>> source {{1,2,3},{4,5,6},{7,8,9}};
    const std::vector<std::vector<int>> source {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};

    std::cout << snail(source) << std::endl;

    return a.exec();
}

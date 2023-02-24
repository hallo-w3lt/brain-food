/*
* Copyright (c) 2023 - @hallo_w3lt
* IDE Qt Creator
*/

#include <QCoreApplication>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> vector {1, 2, 3, 4, 5};

    // We traverse the vector with an iterator and print it
    std::vector<int>::iterator it {vector.begin()};
    while (it != vector.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // We remove the second element of the vector using the iterator
    it = vector.erase(vector.begin() + 1);

    // We traverse the vector again with the updated iterator
    it = vector.begin();

    while (it != vector.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;


    return a.exec();
}

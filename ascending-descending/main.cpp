/*
* Copyright (c) 2023 - @hallo_w3lt
* IDE Qt Creator
*/

#include <QCoreApplication>
#include <iostream>
#include <set>
#include <functional>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::set<int> ascending {5,3,4,2,1};
    std::cout << "Ascending numbers";

    for(int const& number: ascending)
    {
        std::cout << " " << number;
    }
    std::cout << std::endl;

    std::set<int, std::greater<int>> descending {5,3,4,2,1};
    std::cout << "Descending numbers:";

    for(int const& number: descending)
    {
        std::cout << " " << number;
    }
    std::cout << std::endl;


    return a.exec();
}

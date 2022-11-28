/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3OIx0uH
*/

#include <QCoreApplication>
#include <iostream>
#include <string>
#include <utility>

// std::move allow change l-value category to r-value

template<class T>
void swapping_by_move(T& a, T& b)
{
    T tmp{std::move(a)};
    a = std::move(b);
    b = std::move(tmp);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string x{"start"};
    std::string y{"end"};

    std::cout << "before swap" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    swapping_by_move(x, y); // x and y are l-values

    std::cout << "after swap" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    return a.exec();
}

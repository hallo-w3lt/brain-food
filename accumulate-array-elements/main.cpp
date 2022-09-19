/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
*/

#include <QCoreApplication>
#include <iostream>
#include <array>

int sum(std::array<int, 5> const& source)
{
    return 0 == source.size() ? 0 : std::accumulate(source.begin(), source.end(), 0);
}

int multiply(std::array<int, 5> const& source)
{
    return 0 == source.size() ? 0 : std::accumulate(source.begin(), source.end(), 1, std::multiplies<int>());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // use vector instead of arrays, whenever possible
    constexpr std::array<int,5> source {1,2,3,4,5};

    std::cout << "sum:" << sum(source) << std::endl;            // 15
    std::cout << "multiply:" << multiply(source) << std::endl;  // 120


    return a.exec();
}

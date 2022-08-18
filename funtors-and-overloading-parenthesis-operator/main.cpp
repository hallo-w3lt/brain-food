/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3K6CBbG
*/

#include <QCoreApplication>
#include <iostream>

// With functors, you no longer need to create a static variable to hold the value in memory

class Counter final
{
private :
    int m_counter {0};

public:
    int operator()(int const c, bool const add = true)
    {
        return add ? m_counter += c : m_counter -= c;
    };
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter counter1{};
    Counter counter2{};

    std::cout << counter1(10) << std::endl;         // print 10
    std::cout << counter1(20) << std::endl;         // print 30

    std::cout << counter2(5) << std::endl;          // print 5
    std::cout << counter2(10) << std::endl;         // print 15

    std::cout << counter1(20) << std::endl;         // print 50

    std::cout << counter1(40, false) << std::endl;  // print 10
    std::cout << counter2(10, false) << std::endl;  // print 5

    return a.exec();
}

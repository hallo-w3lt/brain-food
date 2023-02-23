/*
* Copyright (c) 2023 - @hallo_w3lt
* IDE Qt Creator
*/

#include <QCoreApplication>
#include <iostream>
#include <string>
#include <variant>

struct Visitor
{
    void operator()(const std::string&  source)
    {
        std::cout << "a string: " << source << std::endl;
    }

    void operator()(const int&  source)
    {
        std::cout << "a int: " << source << std::endl;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::variant<std::string, int> variant {42};

    std::cout << "The variant contains: " << get<int>(variant) << std::endl;

    // using std::visit

    Visitor visitor;
    std::cout << "The variant contains: ";
    std::visit(visitor, variant);

    variant = std::string{"Hello World"};
    std::cout << "The variant contains: ";
    std::visit(visitor, variant);

    return a.exec();
}

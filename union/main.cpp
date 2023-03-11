/*
* Copyright (c) 2023 - @hallo_w3lt
* IDE Qt Creator
*/

#include <QCoreApplication>
#include <iostream>

union Shape
{
    double radio;
    double side;

    struct
    {
        double base;
        double height;
    } triangle;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Shape shape;

    shape.radio = 5.0;
    std::cout << "the radius of the circle is: " << shape.radio << std::endl;

    shape.side = 4.0;
    std::cout << "the side of the square is: " << shape.side << std::endl;

    shape.triangle.base = 3.0;
    shape.triangle.height = 2.0;
    std::cout << "the base of the triangle is: " << shape.triangle.base << std::endl;
    std::cout << "the height of the triangle is: " << shape.triangle.height << std::endl;


    // You have to be careful with this:
    std::cout << " --- " << std::endl;
    std::cout << " !! the radius of the circle is: " << shape.radio << std::endl;

    return a.exec();
}

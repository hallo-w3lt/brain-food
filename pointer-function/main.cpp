/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from https://bit.ly/3dvWqgU
*/

#include <QCoreApplication>
#include <iostream>

int addition(int x, int y)
{
    return x + y;
}

int subtraction(int x, int y)
{
    return x - y;
}

int multiplication(int x, int y)
{
    return x * y;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto const is_valid
    {
        []()
        {
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "oops, invalid input" << std::endl;

                return false;
            }

            return true;
        }
    };

    int x {0};
    while(true)
    {
        std::cout << "Enter the first value: ";
        std::cin >> x;
        if (is_valid()) { break; }
        else { std::cout<<"try again"<<std::endl;  }
    }

    int y {0};
    while(true)
    {
        std::cout << "Enter the second value: ";
        std::cin >> y;
        if (is_valid()) { break; }
        else { std::cout<<"try again"<<std::endl;  }
    }

    int option {0};
    do
    {
        std::cout << "Please choose an option [1. addition, 2. subtraction, 3. multiplication]: ";
        std::cin >> option;

    }while (option <= 0 || option > 3);

    // pointer function
    int (*fnc_ptr)(int, int) {nullptr};

    switch (option)
    {
    case 1: fnc_ptr = addition; break;
    case 2: fnc_ptr = subtraction; break;
    case 3: fnc_ptr = multiplication; break;
    default: break;
    }

    std::cout << "solution: " << fnc_ptr(x,y) << std::endl;

    return a.exec();
}

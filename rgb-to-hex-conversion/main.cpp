/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <sstream>

// The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned.
// Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.
//
// Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.
//
// The following are examples of expected output values:
//
// rgb(255, 255, 255) # returns FFFFFF
// rgb(255, 255, 300) # returns FFFFFF
// rgb(0,0,0) # returns 000000
// rgb(148, 0, 211) # returns 9400D3

// Describe(ExampleTests)
// {
//     It(BasicTests)
//     {
//         Assert::That(RGBToHex::rgb(0,0,0), Equals("000000"));
//         Assert::That(RGBToHex::rgb(1,2,3), Equals("010203"));
//         Assert::That(RGBToHex::rgb(255,255,255), Equals("FFFFFF"));
//         Assert::That(RGBToHex::rgb(254,253,252), Equals("FEFDFC"));
//         Assert::That(RGBToHex::rgb(-20,275,125), Equals("00FF7D"));
//     }
// };

class RGBToHex
{
public:
    static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::rgb(int r, int g, int b)
{
    auto to_hex
    {
        [](int n)-> const std::string
        {
            std::stringstream out {};
            out << std::uppercase << std::hex << std::setfill('0') << std::setw(2) << std::max(0, std::min(n, 255));
            return out.str();
        }
    };

    return 0 == r+g+b ? "000000" : to_hex(r) + to_hex(g) + to_hex(b);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << RGBToHex::rgb(-20,275,125) << std::endl;

    return a.exec();
}

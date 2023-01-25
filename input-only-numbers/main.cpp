/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3OIx0uH
*/

#include <QCoreApplication>
#include <iostream>
#include <charconv>
#include <optional>
#include <string>
#include <string_view>

std::optional<int> string_to_int(std::string_view source)
{
    int out {0};
    auto end{source.data() + source.length()};

    if (std::from_chars(source.data(), end, out).ptr != end)
    {
        return {};
    }

    if (out < 0) {return {};}

    return out;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number {0};

    while(true)
    {
        std::cout << "Enter a positive number: ";
        std::string source{};
        std::getline(std::cin >> std::ws, source);

        if (auto buffer{string_to_int(source)})
        {
            number = *buffer;
            break;
        }
    }

    std::cout << "The number is: " << number << std::endl;

    return a.exec();
}

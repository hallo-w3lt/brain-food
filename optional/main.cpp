/*
* Copyright (c) 2023 - @hallo_w3lt
* IDE Qt Creator*
*/

#include <QCoreApplication>
#include <iostream>
#include <optional>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::optional<int> current_hour = std::nullopt;
    if (not current_hour.has_value())
    {
        std::cout << "We don't know the time" << std::endl;
    }

    current_hour = std::make_optional(18);
    if (current_hour.has_value())
    {
        std::cout << "Current hour is: " << current_hour.value() << std::endl;
    }

    std::optional<std::string> name = std::nullopt;
    std::cout << "Hi, " << name.value_or("John Doe") << std::endl;

    name = std::make_optional("Jane Doe");
    std::cout << "Hi, " << name.value_or("John Doe") << std::endl;

    return a.exec();
}

/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>
#include <regex>
#include <iterator>

// Return the number (count) of vowels in the given string.
int solution(const std::string& source){
    const std::regex rx(R"([aeiou]{1})", std::regex_constants::icase);
    return std::distance(std::sregex_iterator(source.begin(), source.end(), rx), std::sregex_iterator());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const std::string source {"C++ is beautiful"};
    std::cout << "result: " << solution(source) << std::endl;

    return a.exec();
}

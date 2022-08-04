/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>

// It(Sample_Test_Cases)
//   {
//     Assert::That(solution("abcde", "cde"), Equals(true));
//     Assert::That(solution("abcde", "abc"), Equals(false));
//     Assert::That(solution("abc", ""), Equals(true));
//   }
bool solution(std::string const &source, std::string const &ending) {
    const size_t sizeSource {source.length()};
    const size_t sizeEnding {ending.length()};

    return sizeEnding <= sizeSource && sizeSource - source.rfind(ending) == sizeEnding;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "result: " << std::boolalpha << solution("abcde", "cde") << std::endl;

    return a.exec();
}

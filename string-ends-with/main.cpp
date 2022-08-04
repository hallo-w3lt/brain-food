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
    const size_t source_len {source.length()};
    const size_t ending_len {ending.length()};

    return ending_len <= source_len && source_len - source.rfind(ending) == ending_len;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "result: " << std::boolalpha << solution("abcde", "cde") << std::endl;

    return a.exec();
}

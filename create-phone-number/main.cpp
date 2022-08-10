/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>

// Write a function that accepts an array of 10 integers (between 0 and 9),
// that returns a string of those numbers in the form of a phone number.

// Describe(CreatePhoneNumber) {
//     It(BasicTests) {
//         Assert::That(createPhoneNumber(arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}), Equals("(123) 456-7890"));
//         Assert::That(createPhoneNumber(arr{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}), Equals("(111) 111-1111"));
//         Assert::That(createPhoneNumber(arr{1, 2, 3, 4, 5, 6, 8, 8, 0, 0}), Equals("(123) 456-8800"));
//         Assert::That(createPhoneNumber(arr{0, 2, 3, 0, 5, 6, 0, 8, 9, 0}), Equals("(023) 056-0890"));
//         Assert::That(createPhoneNumber(arr{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), Equals("(000) 000-0000"));
//     }
// };

std::string solution(const int source[], const size_t size) {
    const auto format
    {
        [&]()->std::string {

            std::string numbers {};
            for (int i {0}; i < static_cast<int>(size); ++i) {
                numbers += std::to_string(source[i]);
            }

            return {"(" + numbers.substr(0, 3) + ") " + numbers.substr(3, 3) + "-" + numbers.substr(6, 4)};
        }
    };

    return size >= 10 ? format() : "";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    constexpr int source[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    constexpr size_t size{std::size(source)};
    std::cout << "solution: " << solution(source, size) << std::endl;

    return a.exec();
}

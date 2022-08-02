/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>
#include <bitset>

// Implement a function that adds two numbers together and returns their sum in binary.
// The conversion can be done before, or after the addition.
// The binary number returned should be a string.
// Describe(SamplteTests)
// {
//     It(should_pass_sample_tests)
//     {
//         Assert::That(add_binary(1, 1), Equals("10"), ExtraMessage("Invalid result for a = 1, b = 1"));
//         Assert::That(add_binary(0, 1), Equals("1"), ExtraMessage("Invalid result for a = 0, b = 1"));
//         Assert::That(add_binary(1, 0), Equals("1"), ExtraMessage("Invalid result for a = 1, b = 0"));
//         Assert::That(add_binary(2, 2), Equals("100"), ExtraMessage("Invalid result for a = 2, b = 2"));
//         Assert::That(add_binary(51, 12), Equals("111111"), ExtraMessage("Invalid result for a = 51, b = 12"));
//     }
// };
std::string solution(const uint64_t a, const uint64_t b) {
    std::string mask {std::bitset<128>(a + b).to_string()};
    const std::string result {mask.erase(0, std::min(mask.find_first_not_of('0'), mask.size()))};

    return result.length() > 0 ? result: "0";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << solution(51, 12) << std::endl;

    return a.exec();
}

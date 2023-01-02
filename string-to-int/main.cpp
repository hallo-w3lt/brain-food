/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

// In this kata we want to convert a string into an integer. The strings simply represent the numbers in words.
//
// Examples:
//
// "one" => 1
// "twenty" => 20
// "two hundred forty-six" => 246
// "seven hundred eighty-three thousand nine hundred and nineteen" => 783919
// Additional Notes:
//
// The minimum number is "zero" (inclusively)
// The maximum number, which must be supported is 1 million (inclusively)
// The "and" in e.g. "one hundred and twenty-four" is optional, in some cases it's present and in others it's not
// All tested numbers are valid, you don't need to validate them

const std::unordered_map<std::string, int> units = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"thirty", 30},
    {"forty", 40},
    {"fifty", 50},
    {"sixty", 60},
    {"seventy", 70},
    {"eighty", 80},
    {"ninety", 90}
};

const std::unordered_map<std::string, int> multipliers = {
    {"hundred", 100},
    {"thousand", 1000},
    {"million", 1000000}
};

std::vector<std::string> split(std::string source, char delimiter = ' ')
{
    source.erase(source.begin(), std::find_if(source.begin(), source.end(), [](int ch)
    {
        return !std::isspace(ch);
    }));

    source.erase(std::find_if(source.rbegin(), source.rend(), [](int ch)
    {
        return !std::isspace(ch);
    }).base(), source.end());

    std::vector<std::string> words {};
    size_t start {0};
    size_t end {0};

    while((end = source.find(delimiter, start)) != std::string::npos)
    {
        words.push_back(source.substr(start, end-start));
        start = end + 1;
    }

    words.push_back(source.substr(start));
    words.resize(words.size());
    return words;
}

int parse_int(std::string& snumber) {
    std::replace(snumber.begin(), snumber.end(), '-', ' ');
    const auto words = split(snumber, ' ');
    int number {0};

    for (const auto& word : words)
    {
        if (const auto it {units.find(word)}; it != units.end())
        {
            number += it->second;
        }
        if (const auto it {multipliers.find(word)}; it != multipliers.end())
        {
            number += it->second * (number % it->second) - (number % it->second);
        }
    }
    return number;
}

void test_parse_int() {
    std::vector<std::pair<std::string, int>> tests {
        {"zero", 0},
        {"one", 1},
        {"twenty", 20},
        {"forty-six", 46},
        {"one hundred", 100},
        {"two hundred and forty-six", 246},
        {"seven hundred eighty-three thousand nine hundred and nineteen", 783919}
    };
    for (auto& test : tests)
    {
        std::cout << "Source: '" << test.first << "' Expected: " << test.second << " Output: " << parse_int(test.first) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test_parse_int();

    return a.exec();
}

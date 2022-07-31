/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>

// do_test("abcdefg", {"ab", "cd", "ef", "g_"});
// do_test("abcdefg", {"abc", "def", "g__"});
std::vector<std::string> solution(const std::string& source, size_t group = 2){

    std::vector<std::string> slices;
    size_t counter{0};
    while (counter < source.size() && group > 0)
    {
        std::string slice{source.substr(counter, group)};
        if (slice.length() < group)
        {
            std::string last(group - slice.length(), '_');
            for (const auto &item: last)
            {
                slice.push_back(item);
            }
        }

        slices.push_back(slice);
        counter += group;
    }

    return slices;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const std::string word {"HalloW3lt"};
    std::vector<std::string> slices{solution(word)};

    for (const auto& slice: slices) {
        std::cout << slice << std::endl;
    }

    return a.exec();
}

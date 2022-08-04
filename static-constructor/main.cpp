/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3JvYiBJ
*/

#include <QCoreApplication>
#include <iostream>

// C++ doesn't support static constructors, but you can emulate how they work like this:

class Alphabet {
public:
    static std::vector<char> s_letters;

    class StaticBoot {
    public:
        StaticBoot() {
            for (char c{ 'a' }; c <= 'z'; ++c)
            {
                s_letters.push_back(c);
            }
        }
    };

private:
    static StaticBoot s_initializer;
};

// defining our static member variable
std::vector<char> Alphabet::s_letters{};
// defining our static initializer, which will call the StaticBoot constructor, which will initialize s_letters
Alphabet::StaticBoot Alphabet::s_initializer{};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // through the class
    for(const auto& letter: Alphabet::s_letters) {
        std::cout << letter;
    }

    std::cout << std::endl;

    // through an object
    Alphabet alphabet;
    for (const auto& letter: alphabet.s_letters) {
        std::cout << letter;
    }

    std::cout << std::endl;

    return a.exec();
}

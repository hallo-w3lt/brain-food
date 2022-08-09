/*
* Copyright (c) 2022 - thamesis09 && @hallo_w3lt
* IDE Qt Creator
* challenge code taken on https://bit.ly/3BTPlAn
*/

#include <QCoreApplication>
#include <iostream>

// This is a party game:
// You have a number of people A and a coded message
// Each person has a number indicating the position of the next person
// who is going to send the message.
// the first person takes the first letter of the message and passes it to the next,
// the next person receives the string and attaches the next letter
// according to the position of the previous player,
// resend the message to the next position
// until everyone attached the letter of their position

// Example1: A=[3,2,0,1] y S='cdeo'
// R: 'code'
//
// Example2: A=[5,2,0,1,6,4,8,3,7] y S='cdeenetpi'
// R: 'centipede'

std::string solution(const std::vector<int>& people, const std::string& secret) {

    const auto decode
    {
        [&] {

            std::string message {secret.at(0)};
            auto next {people.at(0)};

            for (auto it = secret.begin(); it != secret.end() - 1; ++it) {
                message += secret.at(next);
                next = people.at(next);
            }

            return message;
        }
    };

    return people.size() > 0 && people.size() == secret.length() ? decode() : "";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const std::vector<int> people = {3,2,0,1};
    const std::string secret {"cdeo"}; // code

    std::cout << "solution: " << solution(people, secret) << std::endl;

    return a.exec();
}

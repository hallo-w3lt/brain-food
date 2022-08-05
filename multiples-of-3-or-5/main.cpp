/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>

// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.
// Additionally, if the number is negative, return 0 (for languages that do have them).
// Note: If the number is a multiple of both 3 and 5, only count it once.
int solution(int number)
{
    const auto multiples
    {
        [&]{
            int sum {0};
            for(auto i {3}; i < number; ++i) {
                if (0 == i % 3 || 0 == i % 5) {
                    sum += i;
                }
            }

            return sum;
        }
    };

    return number >= 3 ? multiples() : 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "result: " << solution(10) << std::endl;

    return a.exec();
}

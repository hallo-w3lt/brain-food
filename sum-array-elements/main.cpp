/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
*/

#include <QCoreApplication>
#include <iostream>

// The function should return the sum of the integers of Array, whose index belongs to the [n1;n2] interval
// Array is an array of integers, the n1 and n2 parameters are integers defined by the relation 0 <= n1 <= n2 < array length
// Describe(SamplteTests)
// {
//     It(should_pass_sample_tests)
//     {
//         Assert::That(solution(array, size, 0, 1), Equals(1));
//         Assert::That(solution(array, size, 0, 5), Equals(15));
//         Assert::That(solution(array, size, 0, 0), Equals(0));
//         Assert::That(solution(array, size, 0, 6), Equals(18));
//     }
// };

int solution(const int source[], const int size, const int n1, const int n2) {
    const auto calc
    {
        [&]{
            int sum {0};
            for (auto i {n1}; i <= n2; ++i) {
                sum += source[i];
            }

            return sum;
        }
    };

    return (n1 >= 0 && n2 > n1 && size > n2) ? calc() : 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int source[] = {0,1,2,3,4,5,3};
    const size_t size {std::size(source)};

    std::cout << "result: " << solution(source, size, 0, 5) << std::endl;

    return a.exec();
}

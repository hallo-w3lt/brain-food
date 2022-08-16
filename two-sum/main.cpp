/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>

// Write a function that takes an array of numbers (integers for the tests) and a target number.
// It should find two different items in the array that, when added together, give the target value.
// The indices of these items should then be returned in a tuple / list (depending on your language) like so: (index1, index2).

// two_sum({1, 2, 3}, 4); // returns {0, 2} or {2, 0}

// Describe(test_two_sum)
// {
//     void do_test(const std::vector<int>& numbers, int target) {
//         auto result = two_sum(numbers, target);
//         Assert::That(result.first != result.second);
//         Assert::That(numbers[result.first] + numbers[result.second], Equals(target));
//     }
//     It(should_pass_some_fixed_tests)
//     {
//         Assert::That(two_sum({1, 2, 3}, 4), Fulfills(EqualsUnordered{0, 2}));
//         Assert::That(two_sum({1234, 5678, 9012}, 14690), Fulfills(EqualsUnordered{1, 2}));
//         Assert::That(two_sum({2, 2, 3}, 4), Fulfills(EqualsUnordered{0, 1}));
//     }
// };

std::ostream& operator<< (std::ostream& out, const std::pair<std::size_t, std::size_t> elements)
{
    auto const [n1, n2] {elements};
    return out << "solution: " << "{" << n1 << "," << n2 << "}" << std::endl;
}

std::pair<std::size_t, std::size_t> solution(const std::vector<int>& numbers, const int target)
{
    std::size_t const size {numbers.size()};
    auto sum
    {
        [&]()->std::pair<std::size_t, std::size_t>
        {
            for (int x {0}; x < static_cast<int>(numbers.size()); ++x) {
                for (int y {x+1}; y < static_cast<int>(size); ++y) {

                    if (numbers[x] + numbers[y] == target){
                        return {x, y};
                    }
                }
            }

            return {0,0};
        }
    };

    return (size < 3) ? std::make_pair<std::size_t, std::size_t>(0,0) : sum();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> const source {1, 2, 2};
    int const target {4};

    std::cout << "solution: " << solution(source, target) << std::endl;

    return a.exec();
}

/*
* Copyright (c) 2024 - @hallo_w3lt
* IDE Qt Creator
*/

#include <iostream>
#include <ranges>
#include <format>


int main() {

    //std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto numbers = std::views::iota(1, 5);
    auto processed = numbers
                     | std::views::filter([](int n) { return n % 2 == 0; })
                     | std::views::transform([](int n) { return n * 2; });

    for (int n : processed) {
        std::cout << std::format("result: {}\n\n", n);
    }

    // Output: result: 4
    // Output: result: 8

    return 0;
}

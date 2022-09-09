/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge by www.codewars.com
*/

#include <QCoreApplication>
#include <iostream>
#include <sstream>

// A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more characters.
// The 1st character of a code is a capital letter which defines the book category.
//
// In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0)
// which indicates the quantity of books of this code in stock.
//
// For example an extract of a stocklist could be:
//
// L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
// or
// L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....
// You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :
//
// M = {"A", "B", "C", "W"}
// or
// M = ["A", "B", "C", "W"] or ...
// and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity according to each category.
//
// For the lists L and M of example you have to return the string (in Haskell/Clojure/Racket a list of pairs):
//
// (A : 20) - (B : 114) - (C : 50) - (W : 0)
// where A, B, C, W are the categories, 20 is the sum of the unique book of category A,
// 114 the sum corresponding to "BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W'
// since there are no code beginning with W.
//
// If L or M are empty return string is "" (Clojure and Racket should return an empty array/list instead).
//
// Note:
// In the result codes and their values are in the same order as in M.

// It(Fixed_Tests)
//    {
//        std::vector<std::string> art = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
//        std::vector<std::string> cd = {"A", "B"};
//        dotest(art, cd, "(A : 200) - (B : 1140)");
//        art = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
//        cd = {"A", "B", "C", "D"};
//        dotest(art, cd, "(A : 0) - (B : 1290) - (C : 515) - (D : 600)");
//    }

using book = std::pair<char, int>;

class StockList
{
public:    

    static std::string stockSummary(std::vector<std::string> const& source, std::vector<std::string> const& categories)
    {
        auto searching
        {
            [&]()->std::vector<book>
            {
                std::vector<book> books {};

                for(auto const& category : categories)
                {
                    char const letter {category.at(0)};
                    int qty {0};

                    for (auto const& s: source)
                    {
                        if (letter == s.at(0))
                        {
                            auto const found {s.find(" ")};
                            auto const sqty {s.substr(found, s.size() - found)};
                            qty += std::stoi(sqty);
                        }
                    }

                    books.push_back(std::make_pair(letter, qty));
                }

                return books;
            }
        };


        return 0 == source.size() || 0 == categories.size() ? "" : toString(searching());
    }

private:

    static std::string toString(std::vector<book> const& source)
    {
        std::stringstream out {};
        auto const size {source.size()};
        size_t i {0};

        for(auto const& s: source)
        {
            out << "(" << s.first << " : " << s.second << ")";
            if (++i < size)
            {
                out << " - ";
            }
        }

        return out.str();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<std::string> const source {"CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> const categories {"A", "B", "C", "D"};

    std::cout << "solution: " << StockList::stockSummary(source, categories) << std::endl;

    return a.exec();
}

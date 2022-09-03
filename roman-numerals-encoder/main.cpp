#include <QCoreApplication>
#include <iostream>
#include <string>

// Create a function taking a positive integer as its parameter and returning a string containing the Roman Numeral
// representation of that integer.

// Modern Roman numerals are written by expressing each digit separately starting with the left most digit
// and skipping any digit with a value of zero. In Roman numerals 1990 is rendered:
// 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII.
// 1666 uses each Roman symbol in descending order: MDCLXVI.

// solution(1000); // should return "M"

// Symbol    Value
// I          1
// V          5
// X          10
// L          50
// C          100
// D          500
// M          1,000

// Describe(Kata)
// {
//     It(Fixed_Test)
//     {
//     Assert::That(solution(182) , Equals("CLXXXII"));
//     Assert::That(solution(1990) , Equals("MCMXC"));
//     Assert::That(solution(1875) , Equals("MDCCCLXXV"));
//     }
// };

static std::vector<std::pair<std::string, int>> const table {
    {"I",1},{"IV",4},{"V",5},{"VIII",8},{"IX",9},
    {"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},
    {"CD",400},{"D",500},{"CM",900},{"M",1000}
};

static std::size_t const size{table.size() - 1};

std::string solution(int number){    

    auto calc
    {
        [&]()-> std::string
        {
            std::string roman {};
            std::size_t i {size};
            while(number > 0)
            {
                auto const [symbol, val] = table.at(i);
                auto buf {number / val};
                number = number % val;

                while (buf-- > 0)
                {
                    roman += table.at(i).first;
                }
                --i;
            }
            return roman;
        }
    };

    return number > 0 ? calc() : "";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "solution: " << solution(1990) << std::endl;

    return a.exec();
}

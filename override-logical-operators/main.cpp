/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge code taken on https://bit.ly/3zUmDgj
*/

#include <QCoreApplication>
#include <iostream>
#include <numeric>

// Add six override logical operators

class Fraction {
private:
    int m_numerator{};
    int m_denominator{};

public:
    explicit Fraction(const int numerator = 0, const int denominator = 0): m_numerator{numerator}, m_denominator{denominator}
    {
        reducer();
    }

    void reducer()
    {
        auto const gcd {std::gcd(m_numerator, m_denominator)};

        if (gcd > 0) {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);
    friend bool operator== (const Fraction& f1, const Fraction& f2);
    friend bool operator< (const Fraction& f1, const Fraction& f2);
    friend bool operator> (const Fraction& f1, const Fraction& f2);
    friend bool operator<= (const Fraction& f1, const Fraction& f2);
    friend bool operator>= (const Fraction& f1, const Fraction& f2);
};

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
    out << fraction.m_numerator << '/' << fraction.m_denominator;
    return out;
}

bool operator== (const Fraction& f1, const Fraction& f2)
{
    return f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator;
}

bool operator!= (const Fraction& f1, const Fraction& f2)
{
    return !operator==(f1, f2);
}

bool operator< (const Fraction& f1, const Fraction& f2)
{
    return f1.m_numerator * f2.m_denominator < f2.m_numerator * f1.m_denominator;
}

bool operator> (const Fraction& f1, const Fraction& f2)
{
    return !operator<(f1,f2);
}

bool operator<= (const Fraction& f1, const Fraction& f2)
{
    return operator>(f1,f2);
}

bool operator>= (const Fraction& f1, const Fraction& f2)
{
    return !operator<(f1,f2);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Fraction f1 {3,2};
    Fraction f2 {5,6};

#if 1
    std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << std::endl;
    std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << std::endl;
    std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << std::endl;
    std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << std::endl;
    std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << std::endl;
    std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << std::endl;
#endif

    return a.exec();
}

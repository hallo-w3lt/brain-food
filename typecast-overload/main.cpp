/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3K8AaFz
*/

#include <QCoreApplication>
#include <iostream>

class Cent final
{
public:
    Cent(int cents = 0): m_cents{cents} {}

private:
    int m_cents {0};

public:
    operator int() const {return m_cents;}
    // void setCents(int cents){ m_cents = cents;} // no longer necessary
};

class Eur final
{
public:
    Eur(int eurs = 0): m_eurs {eurs} {}

private:
    int m_eurs {0};

public:
    operator Cent() const {return Cent{m_eurs * 100};};
};

// implicit conversion from a Eur object
std::string to_cents(Cent cents)
{
    return std::to_string(cents);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Eur eurs{5};
    std::cout << "euro cents: " << to_cents(eurs) << std::endl;

    return a.exec();
}

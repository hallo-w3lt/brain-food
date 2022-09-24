/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3Lj3YQr
*/

#include <QCoreApplication>
#include <iostream>

// optional
class IConstraints
{
public:        
    virtual ~IConstraints() = default;

    virtual void implementation() = 0;    
};

// the curiously recurring template pattern (CRTP)
template<typename T>
class Mixin
{
public:
    void name()
    {
        (static_cast<T*>(this))->implementation();
    }
};

class Stuff1 final: public Mixin<Stuff1>, public IConstraints
{
public:
    void implementation() override
    {
        std::cout << "Stuff1::implementation" << std::endl;
    }
};

class Stuff2 final: public Mixin<Stuff2>, public IConstraints
{
public:
    void implementation() override
    {
        std::cout << "Stuff2::implementation" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mixin<Stuff1> mixin1;
    mixin1.name();
    Mixin<Stuff2> mixin2;
    mixin2.name();

    Stuff1 stuff1;
    stuff1.name();
    Stuff2 stuff2;
    stuff2.name();

    return a.exec();
}

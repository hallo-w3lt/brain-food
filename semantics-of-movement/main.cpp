/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3OIx0uH
*/

#include <QCoreApplication>
#include <qtimer.h>
#include <iostream>

template<class T>
class smart_ptr final
{
public:
    explicit smart_ptr(T *ptr = nullptr): m_ptr{ptr}
    {
        // ...
    }

    ~smart_ptr()
    {
        delete m_ptr;
    }

    // avoid construct by copy
    smart_ptr(smart_ptr const& a) = delete;

    // construct by move
    smart_ptr(smart_ptr&& a) noexcept : m_ptr{a.m_ptr}
    {
        a.m_ptr = nullptr;
    }

    smart_ptr& operator=(smart_ptr&& a) noexcept
    {
        if (this == &a){ return *this;}

        // free memory
        delete m_ptr;

        // swapping
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

        return *this;
    }

    bool is_null() const {return nullptr == m_ptr;}

private:
    T* m_ptr = nullptr;
};

class Resource final
{
public:
    explicit Resource() { std::cout << "Resource taken" << std::endl; }
    ~Resource() { std::cout << "Destroyed resource" << std::endl; }
};

smart_ptr<Resource> generate()
{
    smart_ptr<Resource> resource {new Resource};
    return resource; // calling the constructor by move
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    smart_ptr<Resource> resource;
    resource = generate(); // calling assignment by move


    // forcing exit
    QTimer::singleShot(0, &a, SLOT(quit()));
    return a.exec();
}

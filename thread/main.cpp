/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3OIx0uH
*/


#include <QCoreApplication>
#include <iostream>
#include <thread>
#include <functional>

class Counter final
{
public:
    Counter(int id, int it): m_id{id}, m_it{it}
    {
        // ...
    }

    void operator()() const
    {
        for (int i{0}; i < m_it; ++i)
        {
            std::cout << "id: " << m_id << " it: " << i << std::endl;
        }

        std::cout << "--" << std::endl;
    }

private:
    int m_id {};
    int m_it {};
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::thread t1 {Counter{1,4}};
    t1.join();

    Counter counter1{2,6};
    std::thread t2{counter1};
    t2.join();

    Counter counter2{3,8};
    std::thread t3{std::ref(counter2)};
    t3.join();

    return a.exec();
}

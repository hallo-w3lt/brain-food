/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3OIx0uH
*/


#include <QCoreApplication>
#include <iostream>
#include <atomic>
#include <thread>
#include <type_traits>

class Locked final
{
private:
    int m_array[123];
};

class Unlocked final
{
private:
    int m_int;
};

size_t constexpr max {10};

std::atomic<int> a3{0};

void increase()
{
    ++a3;
}

std::atomic<int> a4{0};

void threads()
{
    for (int i {0}; i < max; ++i)
    {
        int previous {a4.fetch_add(1)};
        std::cout << "thread: " << std::this_thread::get_id()
                  << " previous value: " << previous
                  << " new value:" << a4
                  << std::endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::atomic<Locked> a1;
    std::cout << std::boolalpha << std::is_trivially_copyable_v<Locked> << " " << a1.is_always_lock_free << std::endl;

    std::atomic<Unlocked> a2;
    std::cout << std::boolalpha << std::is_trivially_copyable_v<Unlocked> << " " << a2.is_always_lock_free << std::endl;

    std::thread subprocess[max];

    for (int i {0}; i < max; ++i)
    {
        subprocess[i] = std::thread(increase);
    }

    for (int i {0}; i < max; ++i)
    {
        subprocess[i].join();
    }

    std::cout << "Count A3: " << a3 << std::endl;

    std::thread t1(threads);
    t1.join();

    std::thread t2(threads);
    t2.join();

    std::cout << "A4: " << a4 << std::endl;

    std::cout << " ** Finished **" << std::endl;

    return a.exec();
}

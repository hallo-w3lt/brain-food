/*
* Copyright (c) 2023 - @hallo_w3lt
* IDE Qt Creator
*/

#include <QCoreApplication>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

int counter{0};
std::mutex mutex;
std::recursive_mutex rmutex;
std::shared_mutex smutex;

void increment()
{
    mutex.lock();
    ++counter;
    std::cout << "counting by mutex: " << counter << std::endl;
    mutex.unlock();
}

void try_increment()
{
    if (mutex.try_lock())
    {
        ++counter;
        std::cout << "counting by try mutex: " << counter << std::endl;
        mutex.unlock();
    }
}

void recursive_increment(int n)
{
    rmutex.lock();
    if (n <= 0) {return;}

    ++counter;
    std::cout << "counting by recursive mutex: " << counter << std::endl;
    rmutex.unlock();
    recursive_increment(n - 1);
}

void shared_increment()
{
    smutex.lock_shared();
    try {
        ++counter;
        std::cout << "counting by shared mutex: " << counter << std::endl;
    } catch (...) {
        smutex.unlock_shared();
        throw;
    }

    smutex.unlock_shared();
}

void shared_increment_raii()
{
    std::lock_guard<std::mutex> guard(mutex); // auto lock
    ++counter;
    std::cout << "counting by shared mutex RAII: " << counter << std::endl;
    // auto unlock
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    increment();
    try_increment();
    recursive_increment(5);
    std::thread thread1(shared_increment);
    std::thread thread2(shared_increment);
    shared_increment_raii();

    thread1.join();
    thread2.join();

    std::cout << "--- " << std::endl;
    std::cout << "total count: " << counter << std::endl;

    return a.exec();
}

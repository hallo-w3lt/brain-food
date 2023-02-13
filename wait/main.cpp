/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3OIx0uH
*/


#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>

void increase(std::atomic<int>& a1)
{
    int result {0};
    for (int i {0}; i < 100; ++i)
    {
        ++result;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    a1 += result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::atomic<int> a1 {0};
    std::vector<std::thread> threads {};

    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(std::thread{increase, std::ref(a1)});
    }

    for (auto& t : threads)
    {
        t.join();
    }

    std::cout << "Result: " << a1 << std::endl;

    std::atomic<int> a2 {0};
    std::thread job
    {
        [&a2]
        {
            std::cout << "Subprocess starts waiting" << std::endl;
            a2.wait(0);
            std::cout << "Subprocess wake up, a2: " << a2 << std::endl;
        }
    };

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Set 1 for subprocess" << std::endl;
    a2 = 1;
    a2.notify_all();

    job.join();

    std::cout << "** Finished ** : " << std::endl;

    return a.exec();
}

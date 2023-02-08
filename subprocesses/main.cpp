/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3OIx0uH
*/


#include <QCoreApplication>
#include <iostream>
#include <thread>

class Query final
{
public:
    Query(int id): m_id{id} {}

    void process() { std::cout << "Processing: " << m_id << std::endl; }

private:
    int m_id;
};

int k{0};
thread_local int n{0}; // local for each subprocess

void running(int id)
{
    std::cout << "Thread: " << id << " k: " << k << " n: " << n << std::endl;
    ++k;
    ++n;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Query query {100};
    std::thread t1{ &Query::process, &query};
    t1.join();

    std::thread t2 {running, 1};
    t2.join();

    std::thread t3 {running, 2};
    t3.join();

    std::jthread t4
    {
        [](std::stop_token token)
        {
            int counter {0};
            while (!token.stop_requested())
            {
                std::cout << "Looping1: " << counter << std::endl;
                ++counter;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    };

    std::this_thread::sleep_for(std::chrono::seconds(5));
    t4.request_stop();

    std::jthread t5
    {
        [](std::stop_token token)
        {
            int counter {0};
            while (!token.stop_requested() && counter < 10)
            {
                std::cout << "Looping2: " << counter << std::endl;
                ++counter;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    };

    t5.join(); // waiting to finish thread t5

    std::cout << "Finishing" << std::endl;

    return a.exec();
}

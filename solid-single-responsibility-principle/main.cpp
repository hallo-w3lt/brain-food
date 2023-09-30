/*
* Copyright (c) 2023 - @hallo_w3lt
* IDE Qt Creator
*/

#include <QCoreApplication>
#include <fstream>

/*
   SRP (Single Responsibility Principle): This principle states that a class should have a single responsibility or function within the system.
   In other words, each class should do one thing and do it well. This helps keep the code clean and organized,
   making it easier to maintain and extend in the future.
*/


struct ToDo
{
    std::string title;
    std::vector<std::string> entries;

    ToDo(const std::string &title): title(title) {}

    void add_entry(const std::string &entry)
    {
        static int count = 1;
        entries.push_back(std::to_string(count++) + ": " + entry);
    }

    // Not good
    // void save(const std::string& filename)
    // {
    //     std::ofstream ostrm(filename, std::ios::binary);
    //     for (auto& e : entries)
    //     {
    //         ostrm << e << std::endl;
    //     }
    //     ostrm.close();
    // }
};

struct Flush
{
    static void save(const ToDo& todo, const std::string& filename)
    {
        std::ofstream ostrm(filename, std::ios::binary);
        for (auto& e : todo.entries)
        {
            ostrm << e << std::endl;
        }
        ostrm.close();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ToDo todo {"Dear Diary"};
    todo.add_entry("I ate a bug");
    todo.add_entry("I cried today");

    // Not good
    // todo.save("my-file.txt");

    Flush flush;
    flush.save(todo, "my-todo-record.txt");

    return a.exec();
}

#include <QCoreApplication>
#include <iostream>
#include <charconv>
#include <optional>
#include <string>
#include <string_view>
#include <iomanip>

std::optional<int> string_to_int(std::string_view source)
{
    int out {0};
    auto end{source.data() + source.length()};

    if (std::from_chars(source.data(), end, out).ptr != end)
    {
        return {};
    }

    if (out < 0) {return {};}

    return out;
}

std::size_t size {0};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    while (true)
    {
        std::cout << "Enter a positive number: ";
        std::string source{};
        std::getline(std::cin >> std::ws, source);


        if (auto buffer{string_to_int(source)})
        {
            size = *buffer;
            break;
        }
    }

    double *buffer = new double[size];

    for (std::size_t i {0}; i < size; ++i)
    {
        buffer[i] = (double)i;
    }

    for (std::size_t i {0}; i < size; ++i)
    {
        std::cout << "index: : " << i << " value: : " << std::fixed << std::setprecision(2) << buffer[i] << std::endl;
    }

    delete[] buffer;

    return a.exec();
}

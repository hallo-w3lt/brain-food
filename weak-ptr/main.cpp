/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Original code from @0utKast at https://bit.ly/3OIx0uH
*/

#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <memory>

class Person final {

public:
    Person(std::string const& name): m_name{name}
    {
        std::cout << m_name << " created" << std::endl;
    }

    ~Person()
    {
        std::cout << m_name << " destroyed" << std::endl;
    }

    friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2);

    // turn into weak_ptr to shared_ptr
    std::shared_ptr<Person> const getPartner() const { return m_partner.lock(); }
    std::string const& getName() { return m_name; }

private:
    std::string m_name {};
    std::weak_ptr<Person> m_partner;
};

bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
{
    // if (nullptr == p1 || nullptr == p2) {return false;}
    if (!p1 || !p2) {return false;}

    // swapping values
    p1->m_partner = p2;
    p2->m_partner = p1;

    std::cout << p1->m_name << " is now partner of " << p2->m_name << std::endl;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto jane_doe {std::make_shared<Person>("Jane Doe")};
    auto john_doe {std::make_shared<Person>("John Doe")};

    if (partnerUp(jane_doe, john_doe))
    {
        auto partner {john_doe->getPartner()};
        std::cout << "the partner of " << john_doe->getName() << " is: " << partner->getName() << std::endl;
    }

    // forcing exit
    QTimer::singleShot(0, &a, SLOT(quit()));
    return a.exec();
}

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string surname;
    string name;
    string middleName;

public:
    // Создать человека с ФИО
    Person(string surname, string name, string middleName)
    {
        this->surname = surname;
        this->name = name;
        this->middleName = middleName;
    }
    string getSurname() const
    {
        return surname;
    }

    string getName() const
    {
        return name;
    }
    string getMiddleName() const
    {
        return middleName;
    }

    bool operator<(const Person& p2) const
    {
        return surname < p2.surname;
    }
};

std::ostream& operator<<(std::ostream& os, Person& p)
{
    os << "" << p.getSurname() << " " << p.getName() << " " << p.getMiddleName();
    return os;
}

std::istream& operator>>(std::istream& in, Person& p)
{
    in >> p.surname;
    in >> p.name;
    in >> p.middleName;
    return in;
}

#include <iostream>

using namespace std;

struct Employee
{
    string name;
    int vacationDays;
    int daysUsed;
    Employee(string n = "", int d = 0)
    {
        name = n;
        vacationDays = 10;
        daysUsed = d;
    }
};

int main()
{
    Employee emp = Employee("alice", 5);
}
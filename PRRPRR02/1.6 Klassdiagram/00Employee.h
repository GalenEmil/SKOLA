#include <iostream>
#include <string>
#include "00Person.h"

using namespace std;
// Employee ärver av Person
class Employee : public Person {
public:
    Employee(string name, string personnummer, float salary) : Person(name, personnummer), salary(salary) {}
    // Getters
    float getSalary() {
        return salary;
    };

    void setSalary(float newSalary) {
        salary = newSalary;
        cout << name << " now makes " << salary << "kr per month!" << endl;
    };
    // printDetails får en ny funktion i Employee
    virtual void printDetails() {
        std::cout << name << " is an employee. They make " << salary << "kr per month!" << endl;
    };

private:
    float salary;
};
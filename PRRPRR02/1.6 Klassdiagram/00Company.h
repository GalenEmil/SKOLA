#include <iostream>
#include <string>
#include <vector>
#include "00Person.h"
#include "00Employee.h"

using namespace std;

class Company {
public:
    Company(string name) : name(name) {}
    // Lägger till ett objekt av Person i en vektor, people
    void addPerson(Person *person) {
        people.push_back(person);
    };

    void printAllDetails() {
        cout << "Welcome to " << name << "!" << endl;
        cout << "Our database:" << endl;

        for(Person *person : people) {
            person->printDetails();
        }
    };
/*
    float getAllSalary(){
        float sum = 0;
        for(Employee *employee : employees) {
            sum = employee->getSalary;
        }
        return sum;
    }
*/
private:
    string name;
    vector<Person*> people;
/*    vector<Employee*> employees;*/
};
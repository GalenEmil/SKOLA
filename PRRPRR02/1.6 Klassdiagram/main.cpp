#include <iostream>
#include "00Company.h"
#include "00Employee.h"
#include "00Customer.h"

int main(int argc, char **argv) {
    Company myCompany("My Company Inc.");
    myCompany.addPerson(new Employee("Jens Jensson", "19821212-5122", 40000));
    myCompany.addPerson(new Employee("Anders Andersson", "19880411-9282", 50000));
    myCompany.addPerson(new Customer("Stefan Stefansson", "19901111-1010", 2));

    myCompany.printAllDetails();
}
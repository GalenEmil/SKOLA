#include <iostream>
#include "06Workers.h"

using namespace std;

int main() {
    srand(time(NULL));

    // string name, int age, int salary, string subject
    Teacher teacher1("Mikke Mikael Sund", 60, 600000, "matte");
    // string name, int age, int salary, string specialization, int lifesSaved
    Doctor doctor1("Anders Hansen", 40, 500000, "Cardiology", 1000000);

    doctor1.flex();
    teacher1.flex();

    doctor1.greet();
    teacher1.greet();

    doctor1.amount();

    // Skriv ut random betyg
    teacher1.grade();
    teacher1.grade();
    teacher1.grade();

    teacher1.lesson();

};
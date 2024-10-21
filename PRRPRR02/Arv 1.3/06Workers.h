#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class Worker{
public:
    string name;
    int age;
    int salary;

    Worker(string name, int age, int salary) : name(name), age(age), salary(salary) {}

    // Gemensamma metoder
    void greet(){
        cout << "Hello my name is " << name << endl;
    }

    void flex(){
        cout << name << "'s salary is " << salary << endl;
    }
};

class Teacher : public Worker{
public:
    string subject;

    Teacher(string name, int age, int salary, string subject) : Worker(name, age, salary), subject(subject) {}

    void grade(){
        vector<char> listaBetyg{
            'A','B','C','D','E','F'
            //0,1,2,3,4,5
        };
        int range = (5 - 0 + 1);
        int randomMum = rand() % range + 0;
        cout << "En elev fick " << listaBetyg[randomMum] << " i " << subject << endl;
    }

    void lesson(){
        cout << name << " börjar sin lektion nu" << endl;
    }
};

class Doctor : public Worker{
public:
    string specialization;
    int lifesSaved;

    Doctor(string name, int age, int salary, string specialization, int lifesSaved) : Worker(name, age, salary), specialization(specialization), lifesSaved(lifesSaved){}

    void amount(){
        cout << name << " har räddat " << lifesSaved << " stycken liv" << endl;
    }
};
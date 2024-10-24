#pragma once

#include <iostream>
#include <string>

using namespace std;

// draw() är gemensamt
// name är gemensamt på två bara så den struntar jag i

class NPC {
public:
    virtual void draw() = 0;

};

class Soldier : public NPC{
public:
    Soldier(string name, int hp) :name(name), hp(hp), maxHp(hp) {};

    void draw() {
        cout << name << ": I'm an enemy soldier, grr. " << hp << "/" << maxHp << " HP" <<  endl;
    }

private:
    string name;
    int maxHp;
    int hp;
};

class PetDog : public NPC{
public:
    PetDog(string name, string color) : name(name), color(color) {};

    void draw() {
        cout << name << ": I'm the player's " << color << " pet dog!" << endl;
    }

private:
    string name;
    string color;
};

class Bullet : public NPC{
public:
    Bullet(int damage) : damage(damage) {};

    void draw() {
        cout << "(pew pew)" << endl;
    }

private:
    int damage;
};
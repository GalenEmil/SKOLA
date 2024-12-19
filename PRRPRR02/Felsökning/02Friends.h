#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(string name, int age)
        : name(name), age(age) {};

    string getName() {
        return name;
    };

    int getAge() {
        return age;
    };

    int getFriendCount() {
        return friends.size();
    }

    void addFriend(Person *newFriend) {
        friends.push_back(newFriend);
    };

    Person *getLatestFriend() {
        return friends[friends.size() - 1];
    };

    vector<Person *> getFriends() {
        return friends;
    };

private:
    string name;
    int age;
    vector<Person *> friends;
};
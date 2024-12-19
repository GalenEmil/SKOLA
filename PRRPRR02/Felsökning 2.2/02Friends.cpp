// Programmet innehåller 3st allvarliga fel.
// Använd debuggern och läs igenom koden noggrant för att reda ut dem.
// Se till att svara på frågorna medans du letar fel och åtgärdar dem.

// Frågor
// * Fel #1
//   - Vart uppstår fel #1?
//     Svar: I stringifyPeople funktionen
//   - Vilken sorts fel är fel #1? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: Array out of bounds
//   - Hur kan man åtgärda fel #1?
//     Svar: Göra koden till (people.size()-1); Då matchar index med listans längd
// * Fel #2 
//   - Vart uppstår fel #2?
//     Svar: Rad 104 i 02Friends.cpp
//   - Vilken sorts fel är fel #2? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: Felet är att Gary inte har några vänner och då i metoden getLatestFriend() så använder den en nullpointer
//   - Hur kan man åtgärda fel #2?
//     Svar: Göra ett if statement som kollar om längden av friends listan är null eller 0
// * Fel #3 
//   - Vart uppstår fel #3?
//     Svar: Rad 111 i 02Friends.cpp
//   - Vilken sorts fel är fel #3? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: division by zero
//   - Hur kan man åtgärda fel #3?
//     Svar: Göra totalpeople till ett värde som är längden av allpeople vectorn

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include "02Friends.h"

using namespace std;

string stringifyPeople(vector<Person *> people) {
    if(people.size() == 0) {
        return "None!";
    }

    stringstream stringifier;

    for(int i = 0; i <= (people.size()-1); ++i) {
        stringifier << people[i]->getName();

        if(i != people.size() - 1) {
            stringifier << ", ";
        }
    }

    return stringifier.str();
}

void makeFriends(Person *a, Person *b) {
    a->addFriend(b);
    b->addFriend(a);
}

vector<Person *> getFriendSuggestions(Person *p) {
    vector<Person *> theirFriends = p->getFriends();
    vector<Person *> friendSuggestions;

    for(Person *theirFriend : theirFriends) {
        vector<Person *> theirFriendsFriends = theirFriend->getFriends();
        for(Person *theirFriendsFriend : theirFriendsFriends) {
            bool isThem = theirFriendsFriend == p;
            bool isAlreadySuggested = find(friendSuggestions.begin(), friendSuggestions.end(), theirFriendsFriend) != friendSuggestions.end();
            bool isAlreadyFriends = find(theirFriends.begin(), theirFriends.end(), theirFriendsFriend) != theirFriends.end();

            if(!isThem && !isAlreadySuggested && !isAlreadyFriends) {
                friendSuggestions.push_back(theirFriendsFriend);
            }
        }
    }

    return friendSuggestions;
}

int main() {
    Person person1("John", 37);
    Person person2("Kevin", 55);
    Person person3("Janet", 42);
    Person person4("Dale", 32);
    Person person5("Amelia", 39);
    Person person6("Gary", 52);

    makeFriends(&person1, &person4);
    makeFriends(&person1, &person2);
    makeFriends(&person1, &person5);
    makeFriends(&person2, &person4);
    makeFriends(&person3, &person5);

    vector<Person *> allPeople = {
        &person1, &person2, &person3, &person4, &person5, &person6
    };

    int totalFriends;
    int totalPeople = allPeople.size();

    for(Person *person : allPeople) {
        cout << "Name: " << person->getName() << endl;
        cout << "Age: " << person->getAge() << endl;
        cout << "Friends with: " << stringifyPeople(person->getFriends()) << endl;
        if(person->getFriendCount() != NULL)
            cout << "Most recent friend: " << person->getLatestFriend()->getName() << endl;
        cout << "New friend suggestions: " << stringifyPeople(getFriendSuggestions(person)) << endl;

        totalFriends += person->getFriendCount();
    }

    int averageFriends = (float)(totalFriends / totalPeople);
    cout << "Average number of friends: " << averageFriends << endl;

    return 0;
}
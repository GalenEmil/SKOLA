#pragma once

#include <iostream>
#include <string>

using namespace std;

class HotelRoom {
public:
    int number;
    bool booked;

    void checkIn() {
        booked = true;

        cout << "Room #" << number << ": A guest checked in." << endl;
    }

    void checkOut() {
        booked = false;

        cout << "Room #" << number << ": A guest checked out." << endl;
    }

    void printStatus() {
        cout << "Room #" << number << " is: ";

        if(booked) {
            cout << "Booked" << endl;
        } else {
            cout << "Available" << endl;
        }
    }
};
#pragma once

#include <iostream>
#include <string>

using namespace std;

class HotelRoom {
private:
    int number;
    bool booked;
public:
    // Konstruktor
    HotelRoom(int number, bool booked) : number(number), booked(booked)
    { };
    void checkIn() {
        if (booked == false)
        {
            booked = true;
        } else 
        {
            cout << "Felmeddelande(checkin)" << endl;
        }
        cout << "Room #" << number << ": A guest checked in." << endl;
    }

    void checkOut() {
        if (booked == true)
        {
            booked = false;
        } else 
        {
            cout << "Felmeddelande(checkout)" << endl;
        }

        cout << "Room #" << number << ": A guest checked out." << endl;
    }

    void printStatus() {
        cout << "Room #" << number << " is: ";

        if(booked == true) {
            cout << "Booked" << endl;
        } else {
            cout << "Available" << endl;
        }
    }
};
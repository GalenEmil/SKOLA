#include <iostream>
#include <string>
#include "12KlassHotelRoom.h"

using namespace std;

int main() {
    HotelRoom room1;
    room1.number = 312;
    room1.booked = false;

    HotelRoom room2;
    room2.number = 316;
    room2.booked = false;

    room1.checkIn();
    room1.checkOut();
    room1.checkIn();

    // Vad är problemet?
    // Svara här i en kommentar.
    // När du har skrivit om klassen,
    // ta bort raden nedan.
    room2.number = -55;

    // Vad är problemet?
    // Svara här i en kommentar.
    // Ha kvar raden nedan.
    room2.checkOut();

    room1.printStatus();
    room2.printStatus();
}
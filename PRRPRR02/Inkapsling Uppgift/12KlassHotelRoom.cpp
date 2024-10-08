#include <iostream>
#include <string>
#include "12KlassHotelRoom.h"

using namespace std;

int main() {
    /* Det finns en konstruktor så detta behövs icke.
    HotelRoom room1;
    room1.number = 312;
    room1.booked = false;

    HotelRoom room2;
    room2.number = 316;
    room2.booked = false;
    */
   HotelRoom room1(312, false);
   HotelRoom room2(316, false);

    room1.checkIn();
    room1.checkOut();
    room1.checkIn();

    // Vad är problemet?
    // Svara här i en kommentar.
    // Svar: Jag gjorde number till en privat egenskap. Detta innebär att vi inte kan nå den utanför klassen.
    // Problemet innan var att man kunde ändra egenskapen till ett orimligt värde som -55.
    // När du har skrivit om klassen,
    // ta bort raden nedan.
    // room2.number = -55;

    // Vad är problemet?
    // Svara här i en kommentar.
    // Man kunde checka ut trots att rummet inte ens var bokat eller checka in i rummet trots att det redan var bokat.
    // Jag har fixat det här nu genom att ge felmeddelanden.

    // Ha kvar raden nedan.
    room2.checkOut(); // Fel

    room1.printStatus();
    room2.printStatus();
}
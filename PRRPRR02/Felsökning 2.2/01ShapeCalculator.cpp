// Programmet innehåller 3st allvarliga fel.
// Använd debuggern och läs igenom koden noggrant för att reda ut dem.
// Se till att svara på frågorna medans du letar fel och åtgärdar dem.

// Frågor
// * Fel #1
//   - Vart uppstår fel #1?
//     Svar: På rad 66(i main filen)
//   - Vilken sorts fel är fel #1? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: Funktionen getTotalArea körs trots att man inte har skapat någon shape.
//           Då blir det att den kallar på en null pointer eller 0x0 som det står i debuggern
//   - Hur kan man åtgärda fel #1?
//     Svar: Göra ett if-statement så att den kollar om det finns några shapes som är nullpointers innan den lägger till arean.
//           Och om någon är en nullpointer kommer den inte lägga till den
// * Fel #2 
//   - Vart uppstår fel #2?
//     Svar: I funktionen printallshapes
//   - Vilken sorts fel är fel #2? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: array out of bounds. Den försöker ta index 1 när listan har ett värde.
//   - Hur kan man åtgärda fel #2?
//     Svar: Gör om shapes.size() till (shapes.size() - 1) så index stämmer överens med storlek. 
// * Fel #3 
//   - Vart uppstår fel #3?
//     Svar: I gettotalarea funktionen
//   - Vilken sorts fel är fel #3? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: I gettotalarea funktionen så är float totalarea inte definierat från början så det blir ett random värde från minnet
//   - Hur kan man åtgärda fel #3?
//     Svar: float totalarea = 0;


#include <iostream>
#include <vector>
#include "01Shapes.h"

using namespace std;

int main() {
    Shape2D *shape;
    ShapeCollection shapeCollection;

    do {
        cout << "---------------------------------" << endl;
        cout << "Shapes in the collection: " << endl;
        shapeCollection.printAllShapes();

        shape = nullptr;
        int choice;

        cout << "What kind of shape do you want to add?" << endl;
        cout << " 1. Rectangle" << endl;
        cout << " 2. Circle" << endl;
        cout << " 0. All done" << endl;
        cout << ">";

        cin >> choice;

        if(choice == 1) {
            shape = Rectangle::build();
        } else if(choice == 2) {
            shape = Circle::build();
        }

        shapeCollection.addShape(shape);

    } while(shape != nullptr);



    float totalArea = shapeCollection.getTotalArea();

    
    return 0;
}
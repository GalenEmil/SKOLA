// Programmet innehåller 3st allvarliga fel.
// Använd debuggern och läs igenom koden noggrant för att reda ut dem.
// Se till att svara på frågorna medans du letar fel och åtgärdar dem.

// Frågor
// * Fel #1
//   - Vart uppstår fel #1?
//     Svar: 
//   - Vilken sorts fel är fel #1? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: 
//   - Hur kan man åtgärda fel #1?
//     Svar: 
// * Fel #2 
//   - Vart uppstår fel #2?
//     Svar: 
//   - Vilken sorts fel är fel #2? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: 
//   - Hur kan man åtgärda fel #2?
//     Svar: 
// * Fel #3 
//   - Vart uppstår fel #3?
//     Svar: 
//   - Vilken sorts fel är fel #3? (null pointer, array out of bounds, division by zero, eller annat)
//     Svar: 
//   - Hur kan man åtgärda fel #3?
//     Svar: 


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

    cout << "---------------------------------" << endl;
    float totalArea = shapeCollection.getTotalArea();
    cout << "Total area of all the shapes: " << totalArea << endl;

    return 0;
}
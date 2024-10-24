#include <iostream>
#include <string>
#include "01Shapes.h"
#include <vector>

using namespace std;

int main() {
    // ---- Innan polymorfism ----
    cout << "Innan polymorfism:" << endl;

    // Skapa alla former.
    Circle circle1(2.0);
    Square square2(6.0);
    Triangle triangle1(4.0, 2.0);
    // Ny cirkel
    Circle circle2(4.0);
    // Funkar inte
    // Man kan inte blanda saker med olika storlekar eller olika datatyper i en lista
    // vector<Shapes> lista = {circle1, circle2, square2, triangle1};

    // Räkna ut den totala arean.
    double circ1Area = circle1.area();
    double square2Area = square2.area();
    double tri1Area = triangle1.area();
    // Ny cirkel area
    double circ2Area = circle2.area();
    double totalArea = circ1Area + square2Area + tri1Area + circ2Area;
    // Lägger även till ny cirkel i totalArea
    cout << "Den totala arean är: " << totalArea << endl;


    // ---- Efter polymorfism ----
    cout << "Efter polymorfism:" << endl;
    
    // Skapa alla former.
    Circle ncircle1(2.0);
    Square nsquare2(6.0);
    Triangle ntriangle1(4.0, 2.0);
    // Ny cirkel
    Circle ncircle2(4.0);
    
    // | 4 | 5 | 6 | 4 bytes
    cout << "Size in bytes " << sizeof(int) << endl;
    //  |  1.3  |  0.0  |  1.6  | 8 bytes
    cout << "Size in bytes " << sizeof(double) << endl;
    // |  ?  1.2       |  ?  4       |  ?  1.4       | 16 bytes
    cout << "Size in bytes " << sizeof(Circle) << endl;
    // 16 bytes
    cout << "Size in bytes " << sizeof(Square) << endl;
    // 24 bytes
    cout << "Size in bytes " << sizeof(Triangle) << endl;
    // bytes 8
    cout << "Size in bytes " << sizeof(Shapes) << endl;

    // Pointern för klassen *
    // Minnesadresser för objekten &
    vector<Shapes*> lista = {&ncircle1, &ncircle2, &nsquare2, &ntriangle1};
    double ntotalArea = 0;
    for(Shapes *shape : lista){
        // Kalla metod fast med en pointer ->. Pil istället för punkt
        ntotalArea += shape->area();
    }
    cout << "Den totala arean är: " << ntotalArea << endl;
    return 0;
}
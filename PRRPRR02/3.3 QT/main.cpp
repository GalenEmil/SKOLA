#include <QApplication>
#include "Calculator.h"
#include "TextEditor.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Skapa och visa Calculator-widgeten.
    /*
    Calculator calculator;
    calculator.setWindowTitle("Simple Calculator");
    calculator.resize(300, 200);
    calculator.show();
    */

    // Skapa och visa TextEditor-widgeten.
    
    TextEditor textEditor;
    textEditor.setWindowTitle("My Text Editor");
    textEditor.resize(600, 400);
    textEditor.show();
    

    return app.exec();
}

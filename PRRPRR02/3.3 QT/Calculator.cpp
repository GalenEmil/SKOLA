#include "Calculator.h"
#include <QMessageBox>
#include <QFileDialog>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    auto *layout = new QVBoxLayout(this);
    // De två värden man ger
    input1 = new QLineEdit(this);
    input2 = new QLineEdit(this);

    auto *validator = new QDoubleValidator(this);
    input1->setValidator(validator);
    input2->setValidator(validator);

    layout->addWidget(input1);
    layout->addWidget(input2);
    
    // Knapparna man lägger till
    auto *buttonsLayout = new QHBoxLayout();
    QPushButton *addButton = new QPushButton("Add", this);
    QPushButton *subtractButton = new QPushButton("Subtract", this);
    QPushButton *multiplyButton = new QPushButton("Multiply", this);
    QPushButton *divideButton = new QPushButton("Divide", this);
    QPushButton *clearButton = new QPushButton("Clear", this);
    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(subtractButton);
    buttonsLayout->addWidget(multiplyButton);
    buttonsLayout->addWidget(divideButton);
    buttonsLayout->addWidget(clearButton);

    layout->addLayout(buttonsLayout);

    resultLabel = new QLabel("Result: ", this);
    layout->addWidget(resultLabel);

    connect(addButton, &QPushButton::clicked, this, &Calculator::add);
    connect(subtractButton, &QPushButton::clicked, this, &Calculator::subtract);
    connect(multiplyButton, &QPushButton::clicked, this, &Calculator::multiply);
    connect(divideButton, &QPushButton::clicked, this, &Calculator::divide);
    connect(clearButton, &QPushButton::clicked, this, &Calculator::clear);
}

Calculator::~Calculator() {}

void Calculator::add() {
    double num1 = input1->text().toDouble();
    double num2 = input2->text().toDouble();
    double result = num1 + num2;
    resultLabel->setText("Result: " + QString::number(result));
}

void Calculator::subtract() {
    double num1 = input1->text().toDouble();
    double num2 = input2->text().toDouble();
    double result = num1 - num2;
    resultLabel->setText("Result: " + QString::number(result));
}


void Calculator::multiply() {
    double num1 = input1->text().toDouble();
    double num2 = input2->text().toDouble();
    double result = num1 * num2;
    resultLabel->setText("Result: " + QString::number(result));
}

void Calculator::divide() {
    double num1 = input1->text().toDouble();
    double num2 = input2->text().toDouble();
    if(num2 == 0){
        QMessageBox msgBox;
        msgBox.setText("OPEN YOUR EYES!! YOUR'E DIVIDING BY ZERO");
        msgBox.exec();
    }
    double result = num1 / num2;
    resultLabel->setText("Result: " + QString::number(result));
}

void Calculator::clear() {
    input1->setText("");
    input2->setText("");
    resultLabel->setText("Result: ");
}
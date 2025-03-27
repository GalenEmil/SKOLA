#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleValidator>

class Calculator : public QWidget {
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void add();
    void subtract();
    void multiply();
    void divide();
    void clear();

private:
    QLineEdit *input1;
    QLineEdit *input2;
    QLabel *resultLabel;
};

#pragma once

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class TextEditor : public QWidget {
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);

private slots:
    void clearText();
    void exitProgram();
    void countLetters();
    void saveText();
    void openFile();

private:
    QTextEdit *textArea;
    QPushButton *newButton;
    QPushButton *exitButton;
    QPushButton *letterCountButton;
    QPushButton *saveButton;
    QPushButton *openFileButton;
};

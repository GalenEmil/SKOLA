#include "TextEditor.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <QMessageBox>
#include <QFileDialog>

TextEditor::TextEditor(QWidget *parent) : QWidget(parent) {
    newButton = new QPushButton("New");
    textArea = new QTextEdit();
    exitButton = new QPushButton("Exit");
    letterCountButton = new QPushButton("Letter Count");
    saveButton = new QPushButton("Save");
    openFileButton = new QPushButton("Open File");

    auto *layout = new QVBoxLayout(this);

    auto *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(newButton);
    buttonsLayout->addWidget(exitButton);
    buttonsLayout->addWidget(letterCountButton);
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addWidget(openFileButton);

    layout->addLayout(buttonsLayout);

    layout->addWidget(textArea);


    setLayout(layout);
    setWindowTitle("Simple Text Editor");

    connect(newButton, &QPushButton::clicked, this, &TextEditor::clearText);
    connect(exitButton, &QPushButton::clicked, this, &TextEditor::exitProgram);
    connect(letterCountButton, &QPushButton::clicked, this, &TextEditor::countLetters);
    connect(saveButton, &QPushButton::clicked, this, &TextEditor::saveText);
    connect(openFileButton, &QPushButton::clicked, this, &TextEditor::openFile);
}

void TextEditor::clearText() {
    textArea->clear();
}

void TextEditor::exitProgram()
{
    this->close();
}

void TextEditor::countLetters()
{
    // Gör texten till någon sorts string
    QString text = textArea->toPlainText();
    QMessageBox::information(this, "Letter Count(including spaces)", QString::number(text.size()));
}

void TextEditor::saveText()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Text Files (*.txt)"));

    QStringList fileNames;
    if (dialog.exec())
    fileNames = dialog.selectedFiles();

    QString text = textArea->toPlainText();

    std::ofstream MyFile(fileNames[0].toStdString());

    MyFile << text.toStdString();

    MyFile.close();
}

void TextEditor::openFile()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(tr("Text Files (*.txt)"));

    QStringList fileNames;
    if (dialog.exec())
    fileNames = dialog.selectedFiles();

    std::ifstream MyFile(fileNames[0].toStdString());
    std::stringstream buffer;
    buffer << MyFile.rdbuf();

    std::string textString = buffer.str();

    QString text = QString::fromStdString(textString);

    textArea->setPlainText(text);

    MyFile.close();
}
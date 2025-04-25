#include "widget.h"
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
    setFixedSize(385,490);
}

Widget::~Widget() {}

void Widget::setupUi()
{
    //creating a label
    QFont mainLabel("Times",14,QFont::Bold);
    QLabel *textBoxLabel = new QLabel("Text Box", this);
    textBoxLabel->setFont(mainLabel);
    textBoxLabel->move(5,20);

    QTextEdit *textBox = new QTextEdit(this);
    textBox->resize(385,400);
    textBox->move(0,60);

    connect(textBox,&QTextEdit::textChanged,[=](){
        qDebug() << "Text Changed";
    });


    // create copy pushbutton and make it copy what selected from textBox
    QPushButton *copyButton = new QPushButton("Copy", this);
    copyButton->setMinimumSize(50,25);
    copyButton->move(5,460);
    connect(copyButton,&QPushButton::clicked,[=](){
        textBox->copy();
    });


    // create cut pushbutton and make it copy what selected from textBox
    QPushButton *cutButton = new QPushButton("Cut", this);
    cutButton->setMinimumSize(50,25);
    cutButton->move(80,460);
    connect(cutButton,&QPushButton::clicked,[=](){
        textBox->cut();
    });


    // create paste pushbutton and make it paste text to textbox
    QPushButton *pasteButton = new QPushButton("Paste", this);
    pasteButton->setMinimumSize(50,25);
    pasteButton->move(155,460);
    connect(pasteButton,&QPushButton::clicked,[=](){
        textBox->paste();
    });

    // create undo pushbutton and make it undo the last action in textBox
    QPushButton *undoButton = new QPushButton("Undo", this);
    undoButton->setMinimumSize(50,25);
    undoButton->move(230,460);
    connect(undoButton,&QPushButton::clicked,[=](){
        textBox->undo();
    });

    // create redo pushbutton and make it redo the last action in textBox
    QPushButton *redoButton = new QPushButton("Redo", this);
    redoButton->setMinimumSize(50,25);
    redoButton->move(305,460);
    connect(redoButton,&QPushButton::clicked,[=](){
        textBox->redo();
    });


}






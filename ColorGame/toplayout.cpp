#include "toplayout.h"
#include <QApplication>
TopLayout::TopLayout() : QHBoxLayout()
{
    this->scoreOfPLayer = new class score();
    this->newGame = new QPushButton("New Game");
    this->quit = new QPushButton("Quit");
    QObject::connect(newGame,SIGNAL(clicked()),this,SLOT(this->newGame()));
    QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}


//score *score;
//MyTimer mt;
//MyGrid *gl;
//QPushButton *newGame;
//QPushButton *quit;

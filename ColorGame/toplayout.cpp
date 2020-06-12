#include "toplayout.h"

TopLayout::TopLayout() : QHBoxLayout()
{
    this->scoreOfPLayer = new class score();
    this->gl = new MyGrid(this->mt.timer);
    this->newGame = new QPushButton("New Game");
    this->quit = new QPushButton("Quit");
    QObject::connect(newGame,SIGNAL(clicked()),this,SLOT(this->newGame()));
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(this->quitGame()));
}


//score *score;
//MyTimer mt;
//MyGrid *gl;
//QPushButton *newGame;
//QPushButton *quit;

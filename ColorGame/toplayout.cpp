#include "toplayout.h"
#include "restartgame.h"

#include <QApplication>
//RestartGame *restartGame = new RestartGame();
TopLayout::TopLayout(MyGrid *gl) : QHBoxLayout()
{

    MyGrid *thisGl = gl;
    thisGl->timer = this->mt.timer;
    this->scoreOfPLayer = new class score();
    this->newGame = new QPushButton("New Game");
    this->quit = new QPushButton("Quit");

    QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}


//score *score;
//MyTimer mt;
//MyGrid *gl;
//QPushButton *newGame;
//QPushButton *quit;

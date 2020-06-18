#include "toplayout.h"
#include "restartgame.h"
#include <QApplication>
#include<QLabel>
#include <QDebug>
//RestartGame *restartGame = new RestartGame();

 //Constructor : Take a timer object: timer of player
TopLayout::TopLayout(MyTimer * mt) : QGridLayout()
{
    this->scoreOfPLayer = new class score();   //Score of player
    this->newGame = new ColorButton("#ccffff","New Game", "");   //New Game Button
    this->quit = new ColorButton("#ccffff","Quit", "");   //Quit Button
    this->mt = mt;   // Timer of player
    QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}



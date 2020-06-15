#include "toplayout.h"
#include "restartgame.h"
#include <QApplication>
#include<QLabel>
#include <QDebug>
//RestartGame *restartGame = new RestartGame();
TopLayout::TopLayout(MyTimer * mt) : QGridLayout()
{
    this->scoreOfPLayer = new class score();
    this->newGame = new ColorButton("#ccffff","New Game", "");
    this->quit = new ColorButton("#ccffff","Quit", "");
    this->mt = mt;
    QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}


//void TopLayout::checkScore(QLabel * ab){
//    qInfo() << "HERE IT IS @";
//    if(ColorButton::isScored){

//        this->scoreOfPLayer->scoreNumber++;
//        this->scoreOfPLayer->scoreLabel->setText("Score: 1");
//        ColorButton::isScored = false;
//    }
//}


//score *score;
//MyTimer mt;
//MyGrid *gl;
//QPushButton *newGame;
//QPushButton *quit;

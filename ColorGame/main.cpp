#include<QApplication>
#include<QVBoxLayout>
#include<QSpacerItem>
#include<QDebug>
#include <QRandomGenerator>
#include "colorbutton.h"
#include "mytimer.h"
#include "mygrid.h"
#include "score.h"
#include "toplayout.h"
#include "restartgame.h"
#include <QWindow>
#include <QMainWindow>
using namespace std;
int main(int argc, char* argv[]){
//#ccffff
    QApplication app(argc,argv);
    QWidget *cw = new QWidget;
    QMainWindow *mw = new QMainWindow;  //Main window will be shown to player
    QVBoxLayout *vb = new QVBoxLayout(); // Vertical layout: horizontal + Grid Layout
    MyTimer *mt = new MyTimer(); // Timer of player Will be shown in top part

    RestartGame * restartGame = new RestartGame(); // For Restarting Game, When 'New Game' Button is clicked

    MyGrid *gl = new MyGrid(); //Grid Layout for inserting buttons
    TopLayout *topLayout = new TopLayout(mt);  // Horizontal Layout for Top Part : Time,Score,New Game, Quit Buttons


    restartGame->restartCurrentGame(gl,topLayout); //Set topLayout and gridLayout in restartGame

    QObject::connect(topLayout->newGame,SIGNAL(clicked()),restartGame,SLOT(restartCurrentGame2())); //Connect 'New Game' Button with clicked Signal.
\
//gl->addWidget(randButton,row,col,1,1);


    //Adding childrens to their parents and Some Styles.
    topLayout->addWidget(topLayout->mt->label,0,0,1,1);
    topLayout->addWidget(topLayout->scoreOfPLayer->scoreLabel,0,1,1,1);
    topLayout->addWidget(new QLabel(""),0,2,1,1);
    topLayout->addWidget(new QLabel(""),0,3,1,1);
    topLayout->addWidget(topLayout->newGame,0,4,1,1);
    topLayout->addWidget(topLayout->quit,0,5,1,1);
    topLayout->addWidget(new QLabel(""),1,0,1,1);
    vb->addLayout(topLayout);
    vb->addLayout(gl);

    QSpacerItem *si = new QSpacerItem(0,10,QSizePolicy::Expanding,QSizePolicy::Expanding);




    vb->addSpacerItem(si);
    cw->setLayout(vb);

    cw->resize(900,200);


    mw->setWindowTitle("Card Match Game");
    mw->setCentralWidget(cw);
    mw->resize(900,200);
    mw->show();
    return app.exec();

}

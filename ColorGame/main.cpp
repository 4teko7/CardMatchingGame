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

using namespace std;
int main(int argc, char* argv[]){
//#ccffff
    QApplication app(argc,argv);
    QWidget *cw = new QWidget;
    QVBoxLayout *vb = new QVBoxLayout();
    QHBoxLayout *hb = new QHBoxLayout();

    RestartGame * restartGame = new RestartGame();

    MyGrid *gl = new MyGrid();
    TopLayout *topLayout = new TopLayout(gl);


    restartGame->restartCurrentGame(gl,topLayout);

    QObject::connect(topLayout->newGame,SIGNAL(clicked()),restartGame,SLOT(restartCurrentGame2()));
\


    topLayout->addWidget(topLayout->mt.label);
    topLayout->addWidget(topLayout->scoreOfPLayer->scoreLabel);
    topLayout->addWidget(topLayout->newGame);
    topLayout->addWidget(topLayout->quit);
    vb->addLayout(topLayout);
    vb->addLayout(gl);

    QSpacerItem *si = new QSpacerItem(0,10,QSizePolicy::Expanding,QSizePolicy::Expanding);

    vb->addSpacerItem(si);
    cw->setLayout(vb);
    cw->setWindowTitle("Color Game");
    cw->resize(800,300);
    cw->show();
    return app.exec();

}

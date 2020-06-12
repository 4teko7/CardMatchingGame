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

using namespace std;
int main(int argc, char* argv[]){
//#ccffff
    QApplication app(argc,argv);
    QWidget *cw = new QWidget;
    QVBoxLayout *vb = new QVBoxLayout();
    QHBoxLayout *hb = new QHBoxLayout();
    MyTimer mt;
    TopLayout *topLayout = new TopLayout();

    MyGrid *gl = new MyGrid(mt.timer);

    QString textOfButtons[] = {"cat","dog","apple","orange","laptop","lion","monkey","car","pizza","school","doritos","phone","table","book","fish","cat","dog","apple","orange","laptop","lion","monkey","car","pizza","school","doritos","phone","table","book","fish"};

    int randomNumber = QRandomGenerator::global()->generate() % 50;
    qInfo() << randomNumber;
    for(int i = 0 ; i < randomNumber; i++){
        random_shuffle(std::begin(textOfButtons), std::end(textOfButtons));
    }
    int count = 0;
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 6; col++){
            QString color = "#ccffff";

            ColorButton *randButton = new ColorButton("#ccffff","?",textOfButtons[count++]);
            QObject::connect(randButton, SIGNAL(clicked()),randButton, SLOT(changeText()));
            QObject::connect(randButton, SIGNAL(clicked()),topLayout->scoreOfPLayer, SLOT(checkScore()));

            gl->addWidget(randButton,row,col,1,1);
        }
    }
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

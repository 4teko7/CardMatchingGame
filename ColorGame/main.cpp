#include<QApplication>
#include<QVBoxLayout>
#include<QSpacerItem>
#include<QDebug>
#include <QRandomGenerator>
#include "colorbutton.h"
#include "mytimer.h"
#include "mygrid.h"
#include "score.h"
using namespace std;
int main(int argc, char* argv[]){
//#ccffff
    QApplication app(argc,argv);
    QWidget *cw = new QWidget;
    QVBoxLayout *vb = new QVBoxLayout();
    QHBoxLayout *hb = new QHBoxLayout();
    MyTimer mt;
    MyGrid *gl = new MyGrid(mt.timer);
    score *score = new class score();

    QString textOfButtons[] = {"cat","dog","apple","orange","laptop","lion","monkey","car","pizza","school","doritos","phone","table","book","fish","cat","dog","apple","orange","laptop","lion","monkey","car","pizza","school","doritos","phone","table","book","fish"};

//     next_permutation(begin(textOfButtons), end());
    int randomNumber = QRandomGenerator::global()->generate() % 50;
    qInfo() << randomNumber;
    for(int i = 0 ; i < randomNumber; i++){
        random_shuffle(std::begin(textOfButtons), std::end(textOfButtons));
    }
    int count = 0;
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 6; col++){
//            int colorCode = rand()%3;
            QString color = "#ccffff";
//            if(colorCode == 0) color = "red";
//            else if(colorCode == 1) color = "blue";
//            else color = "green";

            ColorButton *randButton = new ColorButton("#ccffff","?",textOfButtons[count++]);
            QObject::connect(randButton, SIGNAL(clicked()),randButton, SLOT(changeText()));
            QObject::connect(randButton, SIGNAL(clicked()),score, SLOT(checkScore()));

            gl->addWidget(randButton,row,col,1,1);
        }
    }
\
    hb->addWidget(mt.label);
    hb->addWidget(score->scoreLabel);
    vb->addLayout(hb);
    vb->addLayout(gl);

    QSpacerItem *si = new QSpacerItem(0,10,QSizePolicy::Expanding,QSizePolicy::Expanding);

    vb->addSpacerItem(si);
    cw->setLayout(vb);
    cw->setWindowTitle("Color Game");
    cw->resize(800,300);
    cw->show();
    return app.exec();

}

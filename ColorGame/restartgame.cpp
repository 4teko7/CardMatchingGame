#include "restartgame.h"
#include<QDebug>
RestartGame::RestartGame()
{

}
MyGrid *thisGl;
TopLayout *thisTopLayout;
using namespace std;
void RestartGame::restartCurrentGame(MyGrid *gl,TopLayout *topLayout){
     qInfo() << "HERE IT IS RESTART";
    thisGl = gl;
    thisTopLayout = topLayout;

    topLayout->mt->timer->stop();
    topLayout->mt->counter = 0;
    topLayout->mt->label->setText("Time (secs): 0");
    topLayout->mt->timer->start(1000);

    topLayout->scoreOfPLayer->scoreNumber = 0;
    topLayout->scoreOfPLayer->scoreLabel->setText("Score: 0");
    QLabel * ab = new QLabel();
    ab->setText("LABELLL");

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
            QObject::connect(randButton, SIGNAL(clicked()),this, SLOT(isFinished()));

            gl->addWidget(randButton,row,col,1,1);
        }
    }
}



void RestartGame::restartCurrentGame2(){
    qInfo() << "HERE IT IS RESTART2";
    restartCurrentGame(thisGl,thisTopLayout);
}

void RestartGame::isFinished(){
    qInfo() << thisTopLayout->scoreOfPLayer->scoreNumber;
    if(thisTopLayout->scoreOfPLayer->scoreNumber == 15){
        thisTopLayout->mt->timer->stop();
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("You Won!");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->exec();
    }
}

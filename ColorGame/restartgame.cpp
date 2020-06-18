#include "restartgame.h"
#include<QDebug>

//Constructor
RestartGame::RestartGame()
{

}
MyGrid *thisGl;
TopLayout *thisTopLayout;
using namespace std;
void RestartGame::restartCurrentGame(MyGrid *gl,TopLayout *topLayout){  //Restart Game when 'New Game' Button is clicked

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

    //Some Text for buttons
    QString textOfButtons[] = {"cat","dog","apple","orange","laptop","lion","monkey","car","pizza","school","doritos","phone","table","book","fish","cat","dog","apple","orange","laptop","lion","monkey","car","pizza","school","doritos","phone","table","book","fish"};

    int randomNumber = QRandomGenerator::global()->generate() % 50;
    //Changing order of words in every new game
    for(int i = 0 ; i < randomNumber; i++){
        random_shuffle(std::begin(textOfButtons), std::end(textOfButtons));
    }
    int count = 0;
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 6; col++){
            QString color = "#ccffff";

            // Creating Buttons and Connect Them to Necessary Signals
            ColorButton *randButton = new ColorButton("#ccffff","?",textOfButtons[count++]);
            QObject::connect(randButton, SIGNAL(clicked()),randButton, SLOT(changeText()));
            QObject::connect(randButton, SIGNAL(clicked()),topLayout->scoreOfPLayer, SLOT(checkScore()));
            QObject::connect(randButton, SIGNAL(clicked()),this, SLOT(isFinished()));

            gl->addWidget(randButton,row,col,1,1);
        }
    }
}


//call original restartCurrentGame method with parameters
void RestartGame::restartCurrentGame2(){

    restartCurrentGame(thisGl,thisTopLayout);
}
 //Check if game finished
void RestartGame::isFinished(){

    if(thisTopLayout->scoreOfPLayer->scoreNumber == 15){
        thisTopLayout->mt->timer->stop();
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("You Won!");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->exec();
    }
}

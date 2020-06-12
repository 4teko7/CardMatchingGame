#include "restartgame.h"

RestartGame::RestartGame()
{

}

using namespace std;
void RestartGame::restartCurrentGame(MyGrid *gl,TopLayout *topLayout){
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
}

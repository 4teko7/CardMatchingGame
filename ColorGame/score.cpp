#include "score.h"
#include<QDebug>

//Constructor
score::score() : QLabel()
{
this->scoreLabel = new QLabel("Score: 0"); //Score of player
this->scoreLabel->setStyleSheet("QLabel { background-color : white; color : black; }");
}
int score::scoreNumber = 0;  // Score number will go inside scoreLabel


 //If two buttons matches, then score is incremented
void score::checkScore(){
    if(ColorButton::isScored){
        scoreNumber++;
        this->scoreLabel->setText("Score: " + QString::number(scoreNumber));
        ColorButton::isScored = false;
    }
}

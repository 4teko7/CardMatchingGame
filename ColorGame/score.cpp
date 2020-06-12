#include "score.h"

score::score() : QLabel()
{
this->scoreLabel = new QLabel("Score: 0");
}
int score::scoreNumber = 0;

void score::checkScore(){
    if(ColorButton::isScored){
        scoreNumber++;
        this->scoreLabel->setText("Score: " + QString::number(scoreNumber));
        ColorButton::isScored = false;
    }
}

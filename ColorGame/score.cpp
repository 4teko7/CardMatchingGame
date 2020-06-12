#include "score.h"

score::score() : QLabel()
{
this->scoreNumber = 0;
this->scoreLabel = new QLabel("Score: 0");
}

void score::changeScore(){
    this->scoreLabel->setText("Score: " + QString::number(this->scoreNumber + 1));
}

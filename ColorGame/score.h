#ifndef SCORE_H
#define SCORE_H
#include<QLabel>
#include "colorbutton.h"

class score : public QLabel
{

    Q_OBJECT

public:
    score(); //Constructor
    QLabel * scoreLabel; //Score of player
    static int scoreNumber; // Score number will go inside scoreLabel

public slots:
    void checkScore(); //If two buttons matches, then score is incremented

};

#endif // SCORE_H

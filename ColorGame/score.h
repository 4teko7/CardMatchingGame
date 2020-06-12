#ifndef SCORE_H
#define SCORE_H
#include<QLabel>
#include "colorbutton.h"

class score : public QLabel
{

    Q_OBJECT

public:
    score();
    QLabel * scoreLabel;
    static int scoreNumber;

public slots:
    void checkScore();

};

#endif // SCORE_H

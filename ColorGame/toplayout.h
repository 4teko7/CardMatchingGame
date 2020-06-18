#ifndef TOPLAYOUT_H
#define TOPLAYOUT_H
#include "mytimer.h"
#include "score.h"
#include <QHBoxLayout>


class TopLayout : public QGridLayout
{
    Q_OBJECT

public:
    TopLayout(MyTimer * mt); //Constructor : Take a timer object: timer of player
//    void checkScore();
    score *scoreOfPLayer; //Score of player
    ColorButton *newGame; //New Game Button
    ColorButton *quit; //Quit Button
    MyTimer * mt; // Timer of player

};

#endif // TOPLAYOUT_H

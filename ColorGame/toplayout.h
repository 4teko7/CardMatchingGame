#ifndef TOPLAYOUT_H
#define TOPLAYOUT_H
#include "mytimer.h"
#include "score.h"
#include <QHBoxLayout>


class TopLayout : public QGridLayout
{
    Q_OBJECT

public:
    TopLayout(MyTimer * mt);
//    void checkScore();
    score *scoreOfPLayer;
    ColorButton *newGame;
    ColorButton *quit;
    MyTimer * mt;

};

#endif // TOPLAYOUT_H

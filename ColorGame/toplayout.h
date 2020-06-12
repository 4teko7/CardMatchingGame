#ifndef TOPLAYOUT_H
#define TOPLAYOUT_H

#include "score.h"
#include <QHBoxLayout>
#include "mygrid.h"
#include "mytimer.h"


class TopLayout : public QGridLayout
{
    Q_OBJECT

public:
    TopLayout(MyGrid *gl);
    score *scoreOfPLayer;
    MyTimer mt;
    ColorButton *newGame;
    ColorButton *quit;
    MyGrid *thisGl;

};

#endif // TOPLAYOUT_H

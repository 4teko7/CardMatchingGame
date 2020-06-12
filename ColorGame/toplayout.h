#ifndef TOPLAYOUT_H
#define TOPLAYOUT_H

#include "score.h"
#include <QHBoxLayout>
#include "mygrid.h"
#include "mytimer.h"


class TopLayout : public QHBoxLayout
{
    Q_OBJECT

public:
    TopLayout(MyGrid *gl);
    score *scoreOfPLayer;
    MyTimer mt;
    QPushButton *newGame;
    QPushButton *quit;
    MyGrid *thisGl;

};

#endif // TOPLAYOUT_H

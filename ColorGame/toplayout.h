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
    TopLayout();
    score *scoreOfPLayer;
    MyTimer mt;
    MyGrid *gl;
    QPushButton *newGame;
    QPushButton *quit;
};

#endif // TOPLAYOUT_H

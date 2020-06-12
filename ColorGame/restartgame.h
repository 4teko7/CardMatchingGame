#ifndef RESTARTGAME_H
#define RESTARTGAME_H
#include "toplayout.h"
#include "mygrid.h"
#include <QRandomGenerator>
#include <QDebug>
#include "colorbutton.h"

class RestartGame : public QObject
{
    Q_OBJECT

public:
    RestartGame();


public slots:
    void restartCurrentGame(MyGrid *gl,TopLayout *topLayout);
    void restartCurrentGame2();
};

#endif // RESTARTGAME_H

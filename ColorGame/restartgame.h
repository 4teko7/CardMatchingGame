#ifndef RESTARTGAME_H
#define RESTARTGAME_H
#include "toplayout.h"
#include "mygrid.h"
#include <QRandomGenerator>
#include <QDebug>
#include "colorbutton.h"

class RestartGame
{
public:
    RestartGame();
    void restartCurrentGame(MyGrid *gl,TopLayout *topLayout);
};

#endif // RESTARTGAME_H

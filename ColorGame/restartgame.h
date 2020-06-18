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
    RestartGame(); //Constructor


public slots:
    void restartCurrentGame(MyGrid *gl,TopLayout *topLayout); //Restart Game when 'New Game' Button is clicked
    void restartCurrentGame2(); //call original restartCurrentGame method with parameters
    void isFinished(); //Check if game finished
};

#endif // RESTARTGAME_H

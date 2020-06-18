#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>
#include<QLabel>
#include<QMessageBox>

class MyTimer : public QObject
{
    Q_OBJECT

public:
    MyTimer(); //Timer Constructor
    QTimer *timer; //Timer Of Player
    QLabel *label; // Timer Label Will Be Shown
    int counter; //Keeps Seconds

public slots:
    void myTimerSlot(); // Change timer counter according to timeout() signal


};

#endif // MYTIMER_H

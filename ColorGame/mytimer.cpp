#include "mytimer.h"
#include<QTimer>
#include<QMessageBox>

//Timer Constructor
MyTimer::MyTimer()
{

    timer = new QTimer(this);//Timer Of Player
    label = new QLabel("Time (secs): 0");// Timer Label Will Be Shown
    label->setStyleSheet("QLabel { background-color : white; color : black; }");


    counter = 0;//Keeps Seconds

    // Signal And Slot Connection

    connect(timer,SIGNAL(timeout()),this, SLOT(myTimerSlot()));

    timer->start(1000);



}

 // Change timer counter according to timeout() signal
void MyTimer::myTimerSlot() {

    counter += 1;
    label->setText("Time (secs): " + QString::number(this->counter));
    if(counter >= 180){
        this->timer->stop();
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("You Failed!");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->exec();
    }
}

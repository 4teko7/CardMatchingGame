#include "mytimer.h"
#include<QTimer>
#include<QMessageBox>


MyTimer::MyTimer()
{

    timer = new QTimer(this);
    label = new QLabel("Time (secs): 0");
    counter = 0;

    // Signal And Slot Connection

    connect(timer,SIGNAL(timeout()),this, SLOT(myTimerSlot()));

    timer->start(1000);



}


void MyTimer::myTimerSlot() {

    counter += 1;
    label->setText("Time (secs): " + QString::number(this->counter));
    if(counter >= 30){
        this->timer->stop();
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setText("You Failed!");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->exec();
    }
}

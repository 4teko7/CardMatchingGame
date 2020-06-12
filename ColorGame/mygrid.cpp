#include "mygrid.h"
#include<colorbutton.h>

MyGrid::MyGrid(QTimer * timer) : QGridLayout()
{
    this->timer = timer;
}


void MyGrid::checkColors(){
//    bool allSame = true;

//    QString prev = "";
//    for(int i = 0; i < this->count(); i++){
//        ColorButton * widget = qobject_cast<ColorButton*>(this->itemAt(i)->widget());

//        if(prev == ""){
//            prev = widget->color;
//        }else if(prev != widget->color){
//            allSame = false;
//        }


//    }

//    if(allSame){
//        this->timer->stop();
//        QMessageBox msgBox;
//        msgBox.setText("You Won !");
//        msgBox.exec();
//        msgBox.setStandardButtons(QMessageBox::Cancel);
//    }


}

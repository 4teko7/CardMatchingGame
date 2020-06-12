#include "colorbutton.h"
#include<QDebug>
void changePalColor(QPalette & pal, const QString & color);
void updateWindow(QPalette & pal);

ColorButton::ColorButton(const QString & text,QString textOfButton, QWidget * parent)
    : QPushButton(text,parent) {

    this->textOfButton = textOfButton;


    QPalette pal = palette();
//    changePalColor(pal,color);
    updateWindow(pal);



}

QString ColorButton::prevText = "";
QPushButton * ColorButton::prevButton = nullptr;
void ColorButton::changeText(){

    if(this->text() != "?") return;
    if(prevText == "") {
        prevText = this->textOfButton;
        this->setText(this->textOfButton);
        prevButton = this;
    }else{
        if(prevText == this->textOfButton){
            this->setText(this->textOfButton);
        }else{
            prevButton->setText("?");
        }
        prevText = "";
        prevButton = nullptr;
    }


//    QPalette pal = palette();
//    int color = rand() % 3;
//    if(color == 0){
//        this->color = "blue";
//        changePalColor(pal,this->color);
//    }else if(color == 1){
//        this->color = "red";
//        changePalColor(pal,this->color);
//    }else{
//        this->color = "green";
//        changePalColor(pal,this->color);
//    }


}

//void ColorButton::changePalColor(QPalette & pal, const QString & color){

//    if(color == "blue"){
//        pal.setColor(QPalette::Button, QColor(Qt::blue));
//    }else if(color == "red"){
//        pal.setColor(QPalette::Button,QColor(Qt::green));
//    }else{
//        pal.setColor(QPalette::Button,QColor(Qt::green));
//    }
//    updateWindow(pal);
//}

void ColorButton::updateWindow(QPalette & pal){
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();

}

#include "colorbutton.h"
#include<QDebug>
#include <QTimer>


void changePalColor(QPalette & pal, const QString & color);
void updateWindow(QPalette & pal);
QTimer *timer;
ColorButton::ColorButton(const QString & color, const QString & text,QString textOfButton, QWidget * parent)
    : QPushButton(text,parent) {

    this->textOfButton = textOfButton;
    this->color = color;

    QPalette pal = palette();
    changePalColor(pal,color);
    updateWindow(pal);



}

QString ColorButton::prevText = "";
QPushButton * ColorButton::prevButton = nullptr;
QPushButton * ColorButton::currentButton = nullptr;
bool ColorButton::isScored = false;

void ColorButton::changeText(){
    if(this->text() != "?") return;
    if(timer != nullptr) {
        clearText();
    }


    if(prevText == "") {
        prevText = this->textOfButton;
        this->setText(this->textOfButton);
        prevButton = this;
    }else{
        if(prevText == this->textOfButton){
            this->setText(this->textOfButton);
            prevText = "";
            prevButton = nullptr;
            currentButton = this;
            isScored = true;
        }else{
            currentButton = this;
            timer = new QTimer();
            this->setText(this->textOfButton);
            QObject::connect(timer, SIGNAL(timeout()),this, SLOT(clearText()));
            timer->start(700);
        }

    }

}

void ColorButton::clearText(){
    timer->stop();
    currentButton->setText("?");
    prevButton->setText("?");
    prevText = "";
    prevButton = nullptr;
    currentButton = nullptr;
    timer = nullptr;
}

void ColorButton::changePalColor(QPalette & pal, const QString & color){

    pal.setColor(QPalette::Button, QColor(color));

    updateWindow(pal);
}

void ColorButton::updateWindow(QPalette & pal){
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();

}

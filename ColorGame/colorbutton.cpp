#include "colorbutton.h"
#include<QDebug>
#include <QTimer>


void changePalColor(QPalette & pal, const QString & color);
void updateWindow(QPalette & pal);
QTimer *timer;
QTimer *timer2;
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
bool sameFound = false;

void ColorButton::changeText(){
    if(this->text() != "?") return;
    if(timer != nullptr) clearText();
    if(timer2 != nullptr) clearFound();


    if(prevText == "") {
        prevText = this->textOfButton;
        this->setText(this->textOfButton);
        prevButton = this;
    }else{

        if(prevText == this->textOfButton){
            this->setText(this->textOfButton);
            currentButton = this;
            isScored = true;
            sameFound = true;
            timer2 = new QTimer();
            QObject::connect(timer2, SIGNAL(timeout()),this, SLOT(clearFound()));
            timer2->start(700);

        }else{
            currentButton = this;
            timer = new QTimer();
            this->setText(this->textOfButton);
            QObject::connect(timer, SIGNAL(timeout()),this, SLOT(clearText()));
            timer->start(700);
        }

    }

}
void ColorButton::clearFound(){
    timer2->stop();
    currentButton->setText("");
    prevButton->setText("");
    prevText = "";
    prevButton = nullptr;
    currentButton = nullptr;
    timer2 = nullptr;
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

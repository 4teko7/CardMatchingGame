#include "colorbutton.h"
#include<QDebug>
#include <QTimer>


void changePalColor(QPalette & pal, const QString & color);
void updateWindow(QPalette & pal);
QTimer *timer;
QTimer *timer2;

//Constructor : takes, color, text, and default text of button
ColorButton::ColorButton(const QString & color, const QString & text,QString textOfButton, QWidget * parent)
    : QPushButton(text,parent) {

    this->textOfButton = textOfButton;// text of button
    this->color = color;// Color of button

    QPalette pal = palette();
    changePalColor(pal,color);//Change Color
    updateWindow(pal);//Update window



}

QString ColorButton::prevText = "";// Previous clicked button's text
QPushButton * ColorButton::prevButton = nullptr;// Previous clicked button
QPushButton * ColorButton::currentButton = nullptr;// Current clicked button
bool ColorButton::isScored = false;// check if previous and current buttons text match
bool sameFound = false;// check if previous and current buttons text match

//Change text of clicked Buttons
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

// clear text of matched buttons
void ColorButton::clearFound(){
    timer2->stop();
    currentButton->setText("");
    prevButton->setText("");
    prevText = "";
    prevButton = nullptr;
    currentButton = nullptr;
    timer2 = nullptr;
}
// put '?' in not mached buttons
void ColorButton::clearText(){
    timer->stop();
    currentButton->setText("?");
    prevButton->setText("?");
    prevText = "";
    prevButton = nullptr;
    currentButton = nullptr;
    timer = nullptr;
}
//Change Color
void ColorButton::changePalColor(QPalette & pal, const QString & color){

    pal.setColor(QPalette::Button, QColor(color));

    updateWindow(pal);
}
//Update window
void ColorButton::updateWindow(QPalette & pal){
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();

}

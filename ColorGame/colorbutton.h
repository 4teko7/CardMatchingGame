#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include "mytimer.h"
#include<QPushButton>
#include<QPalette>
#include "score.h"


class ColorButton : public QPushButton
{
    Q_OBJECT

public:
    //Constructor : takes, color, text, and default text of button
    ColorButton(const QString & color, const QString & text, QString textOfButton, QWidget * parent = 0);
    QString textOfButton; // text of button
    QString color; // Color of button
    static QPushButton *prevButton; // Previous clicked button
    static QPushButton *currentButton; // Current clicked button
    static QString prevText; // Previous clicked button's text
    static bool isScored; // check if previous and current buttons text match
    void updateWindow(QPalette & pal); //Update window
    void changePalColor(QPalette & pal, const QString & color); //Change Color

public slots:
   void changeText(); //Change text of clicked Buttons
   void clearText(); // put '?' in not mached buttons
   void clearFound(); // clear text of matched buttons


};

#endif // COLORBUTTON_H

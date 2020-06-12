#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include<QPushButton>
#include<QPalette>
#include "score.h"
class ColorButton : public QPushButton
{
    Q_OBJECT

public:

    ColorButton(const QString & text, QString textOfButton, QWidget * parent = 0);
    QString textOfButton;
    static QPushButton *prevButton;
    static QPushButton *currentButton;
    static QString prevText;
    void updateWindow(QPalette & pal);
//    void changePalColor(QPalette & pal, const QString & color);

public slots:
   void changeText();
   void clearText();


};

#endif // COLORBUTTON_H

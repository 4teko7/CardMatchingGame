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

    ColorButton(const QString & color, const QString & text, QString textOfButton, QWidget * parent = 0);
    QString textOfButton;
    QString color;
    static QPushButton *prevButton;
    static QPushButton *currentButton;
    static QString prevText;
    static bool isScored;
    void updateWindow(QPalette & pal);
    void changePalColor(QPalette & pal, const QString & color);

public slots:
   void changeText();
   void clearText();
   void clearFound();


};

#endif // COLORBUTTON_H

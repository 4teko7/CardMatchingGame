#ifndef MYGRID_H
#define MYGRID_H
#include<QGridLayout>
#include<QMessageBox>
#include<QTimer>

class MyGrid : public QGridLayout
{

    Q_OBJECT

public:
    MyGrid(); //Constructor
    QTimer * timer; //Timer Object


public slots:
    void checkColors();
};

#endif // MYGRID_H

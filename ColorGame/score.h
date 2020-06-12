#ifndef SCORE_H
#define SCORE_H
#include<QLabel>

class score : public QLabel
{

    Q_OBJECT

public:
    score();
    QLabel * scoreLabel;
    int scoreNumber;

public slots:
    void changeScore();

};

#endif // SCORE_H

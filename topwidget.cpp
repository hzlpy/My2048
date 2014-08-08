#include "topwidget.h"
#include <QDebug>
TopWidget::TopWidget(QWidget *parent) :
    QWidget(parent)
{
    font.setFamily("Consolas");
    font.setPixelSize(25);
    this->setFont(font);

    scoreLabel = new QLabel("score:",this);
    score = new QLabel("0",this);
    highScoreLabel = new QLabel("HighScore:",this);
    highScore = new QLabel("0",this);
    restartButton = new QPushButton("Restart",this);
    shareButton = new QPushButton("Share",this);
    qGridLayout = new QGridLayout(this);
    qGridLayout->addWidget(scoreLabel,0,0);
    qGridLayout->addWidget(score,1,0);
    qGridLayout->addWidget(highScoreLabel,0,1);
    qGridLayout->addWidget(highScore,1,1);
    qGridLayout->addWidget(restartButton,0,2);
    qGridLayout->addWidget(shareButton,1,2);
    this->setLayout(qGridLayout);
//    scoreLabel->setGeometry(10,10,50,50);
}

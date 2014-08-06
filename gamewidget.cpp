#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent)
{
    init();
}

void GameWidget::init()
{
    this->setGeometry(50,50,400,600);

    vBoxLayout = new QVBoxLayout(this);
    topWidget = new QWidget(this);
    mainWidget = new QWidget(this);

    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(25);

    topWidget->setStyleSheet("background:blue");
    topWidget->setMaximumHeight(150);
    topWidget->setMinimumHeight(150);
    scoreLabel = new QLabel("Score:",topWidget);
    scoreLabel->setGeometry(10,10,180,70);
    scoreLabel->setFont(font);

    highScoreLabel = new QLabel("HighScore:",topWidget);
    highScoreLabel->setGeometry(200,10,180,70);
    highScoreLabel->setFont(font);

    mainWidget->setStyleSheet("background:green");

    int gridSize = 94;
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            QLabel *label = new QLabel(mainWidget);
            label->setStyleSheet("background:#fa33f3 ; border-radius:10");
            label->setGeometry(x*gridSize, y*gridSize, gridSize-2, gridSize-2);
        }
    }

    vBoxLayout->addWidget(topWidget);
    vBoxLayout->addWidget(mainWidget);
    this->setLayout(vBoxLayout);
}



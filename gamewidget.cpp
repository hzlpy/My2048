#include "gamewidget.h"
#include <QDebug>

// 颜色数组 存储每个数字对应的背景色
QColor digitBkg[11] = {QColor::fromRgb(0xFF, 0xFF, 0xCC), QColor::fromRgb(0xFF, 0xFF, 0x99),
                            QColor::fromRgb(0xFF, 0xCC, 0xCC), QColor::fromRgb(0xFF, 0xCC, 0x99),
                            QColor::fromRgb(0xFF, 0x99, 0x99), QColor::fromRgb(0xFF, 0x99, 0x66),
                            QColor::fromRgb(0xFF, 0x66, 0x66), QColor::fromRgb(0xCC, 0x99, 0x66),
                            QColor::fromRgb(0xCC, 0x33, 0x33), QColor::fromRgb(0xCC, 0x00, 0x33),
                            QColor::fromRgb(0xFF, 0x00, 0x00)};

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent)
{
    topWidget = new TopWidget();
    mainWidget = new MainWidget();
    qGridLayout = new QGridLayout();

    qGridLayout->addWidget(topWidget);
    qGridLayout->addWidget(mainWidget);
    qGridLayout->setRowStretch(0,1);
    qGridLayout->setRowStretch(1,4);
    this->setLayout(qGridLayout);
    this->setGeometry(100,100,400,600);
}


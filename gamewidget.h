#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QSplitter>
#include "topwidget.h"
#include "mainwidget.h"
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);

private:
    MainWidget *mainWidget;
    TopWidget *topWidget;
    QGridLayout *qGridLayout;
    QSplitter *qSplitter;
signals:

public slots:

};

#endif // GAMEWIDGET_H

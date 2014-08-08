#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFont>
class TopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopWidget(QWidget *parent = 0);
private:
    QPushButton *restartButton;
    QPushButton *shareButton;
    QLabel *scoreLabel;
    QLabel *score;
    QLabel *highScoreLabel;
    QLabel *highScore;
    QGridLayout *qGridLayout;
    QFont font;
signals:

public slots:

};

#endif // TOPWIDGET_H

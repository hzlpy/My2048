#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);

signals:

private:
    QWidget *topWidget;
    QWidget *mainWidget;
    QVBoxLayout *vBoxLayout;
    QLabel *scoreLabel;
    QLabel *highScoreLabel;
    QPushButton *restartButton;
    QFont font;
    void init();
public slots:

};

#endif // GAMEWIDGET_H

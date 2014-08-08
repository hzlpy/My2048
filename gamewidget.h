#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>
#define WIDTH 4
#define HEIGHT 4

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);

private:
    QWidget *topWidget;
    QWidget *mainWidget;
    QVBoxLayout *vBoxLayout;
    QGridLayout *topGridlayout;
    QGridLayout *gridLayout;
    QLabel *scoreLabel;
    QLabel *highScoreLabel;
    QPushButton *restartButton;
    QLabel *labels[WIDTH][HEIGHT];
    int boards[WIDTH][HEIGHT];
    // 数码的个数 存储当前面板上的数字的个数
    int NumCount;
    // true有效移动
    bool isMove;
    QFont font;
    QPoint startPos;
    QPoint endPos;
    void init();
    void init2Block();
    void freshBoards();
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void printBoards();

signals:
    void signalDirectionMove(int direction);
//    void signalScoreAdd();
//    void signalGameOver();
//    void signalGameWin();
public slots:
    void slotDirectionMove(int direction);
//    void slotGameRestart();
};

#endif // GAMEWIDGET_H

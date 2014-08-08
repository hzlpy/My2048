#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QFont>
#include <QPoint>
#include <QKeyEvent>
#include <QMouseEvent>
#define WIDTH 4
#define HEIGHT 4
class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
private:
    int boards[WIDTH][HEIGHT];
    int NumCount;
    QFont font;
    QGridLayout *qGridLayout;
    QLabel *labels[WIDTH][HEIGHT];
    QPoint startPos;
    QPoint endPos;

    void init2Blocks();
    void initBoard();
    void freshBoard();
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

signals:
    void signalDirectionMove(int direction);
public slots:
    void slotDirectionMove(int direction);
};

#endif // MAINWIDGET_H

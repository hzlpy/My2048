#include "mainwidget.h"
#include <QDebug>
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    init2Blocks();
    initBoard();
    connect(this,SIGNAL(signalDirectionMove(int)),this,SLOT(slotDirectionMove(int)));
}

void MainWidget::initBoard()
{
    NumCount = 0;

    font.setFamily("Consolas");
    font.setPixelSize(25);
    this->setFont(font);

    qGridLayout = new QGridLayout(this);
    for(int y=0; y<HEIGHT; y++)
    {
        for(int x=0; x<WIDTH; x++)
        {
            QLabel *label = new QLabel(this);
            label->setStyleSheet("background:#ffffcc ; border-radius:10");
            qGridLayout->addWidget(label,x,y);
            labels[x][y] = label;
            if(boards[x][y] != 0)
            {
                label->setText(QString::number(boards[x][y],10));
                label->setFont(font);
                label->setAlignment(Qt::AlignCenter);
            }
        }
    }
    this->setLayout(qGridLayout);
}

void MainWidget::init2Blocks()
{
    memset(boards, 0, sizeof(boards));

    boards[rand() % 4][rand() % 4] = 2;
    int i = rand() % 4, j = rand() % 4;
    while (boards[i][j] != 0)
        i = rand() % 4, j = rand() % 4;
    boards[i][j] = 2;
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    int direction = -1;
    switch (event->key()) {
    case Qt::Key_Up:
        direction = 0;
        break;
    case Qt::Key_Down:
        direction = 1;
        break;
    case Qt::Key_Left:
        direction = 2;
        break;
    case Qt::Key_Right:
        direction = 3;
        break;
    }
    emit signalDirectionMove(direction);
}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
    startPos = event->pos();
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    endPos = event->pos();
    float dx = endPos.x() - startPos.x();
    float dy = endPos.y() - startPos.y();
    int direction = -1;
    //通过dx，dy来判断手势的方向
    if(abs(dx) < abs(dy))
    {
        if(dy < 0)
        {
            direction = 0;
        }
        else {
            direction = 1;
        }
    }else{
        if(dx < 0)
        {
            direction = 2;
        }else{
            direction = 3;
        }
    }
    emit signalDirectionMove(direction);
}

/**
 * @author Zhangle
 * @brief GameWidget::slotDirectionMove 键盘上下左右键被按下后分别进行响应
 * @param direction 方向 0 1 2 3 分别代表上下左右
 */
void MainWidget::slotDirectionMove(int direction)
{
    int i,j,k;
    i = j = k = 0;
    //记录某个格子是否参与过合并
    bool isCombined[WIDTH][HEIGHT];
    memset(isCombined, 0, sizeof(isCombined));
    switch(direction)
    {
    case 0:// Up
        qDebug() << "Up";
        for (i = 0; i < 4; i++)
        {
            j = 0, k = 0;
            while (true)
            {
                while (j < 4 && boards[j][i] == 0)
                    j++;
                if (j > 3)
                    break;
                qSwap(boards[k][i], boards[j][i]);
                if (k > 0 && boards[k][i] == boards[k - 1][i])
                {
                    boards[k - 1][i] <<= 1;
                    boards[k][i] = 0;
                }
                else
                    k++;
                j++;
            }
        }
        break;
    case 1: //Down
        qDebug() << "Down";
        for(i=0; i<4; i++)
        {
            j = k = 3;
            while(true)
            {
                while(j>-1 && boards[j][i]==0)
                {
                    j--;
                }
                if(j<0)
                {
                    break;
                }
                qSwap(boards[k][i], boards[j][i]);
                if (k < 3 && boards[k][i] == boards[k + 1][i])
                 {
                     boards[k + 1][i] <<= 1;
                     boards[k][i] = 0;
                 }
                 else
                {
                    k--;
                }
                j--;
            }
        }
        break;
    case 2:
        qDebug() << "Left";
        for(i=0; i<4; i++)
        {
            j = k = 0;
            while(true)
            {
                while(j<4 && boards[i][j] == 0)
                {
                    j++;
                }
                if(j>3)
                {
                    break;
                }
                qSwap(boards[i][k],boards[i][j]);
                if (k > 0 && boards[i][k] == boards[i][k - 1])
                {
                    boards[i][k - 1] <<= 1;
                    boards[i][k] = 0;
                }
                else
                    k++;
                j++;
            }
        }
        break;
    case 3:
        qDebug() << "Right";
        for (i = 0; i < 4; i++)
        {
            j = 3, k = 3;
            while (true)
            {
                while (j > -1 && boards[i][j] == 0)
                    j--;
                if (j < 0)
                    break;
                qSwap(boards[i][k], boards[i][j]);

                if (k < 3 && boards[i][k] == boards[i][k + 1])
                {
                    boards[i][k + 1] <<= 1;
                    boards[i][k] = 0;
                }
                else
                    k--;
                j--;
            }
        }
        break;
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(boards[i][j] != 0)
            {
                NumCount ++;
            }
        }
    }
    if(NumCount != 4*4)
    {
        // 随机产生行号和列号
        i = rand() % 4, j = rand() % 4;
        // 循环直到行和列对应的元素为0
        while (boards[i][j] != 0)
            i = rand() % 4, j = rand() % 4;
        // 填入2
        boards[i][j] = (rand() % 2 + 1) * 2;
    }
    freshBoard();
//    printBoards();
}


void MainWidget::freshBoard()
{
    for(int y=0; y<HEIGHT; y++)
    {
        for(int x=0; x<WIDTH; x++)
        {
            labels[x][y]->setText("");
            labels[x][y]->setStyleSheet("background:#ffffcc; border-radius:10");
            if(boards[x][y] != 0)
            {
                labels[x][y]->setText(QString::number(boards[x][y],10));
                labels[x][y]->setFont(font);
                labels[x][y]->setAlignment(Qt::AlignCenter);
                switch (boards[x][y]) {
                case 2:
                    labels[x][y]->setStyleSheet("background:#ffffcc; border-radius:10");
                    break;
                case 4:
                    labels[x][y]->setStyleSheet("background:#ffff99; border-radius:10");
                    break;
                case 8:
                    labels[x][y]->setStyleSheet("background:#ffcccc; border-radius:10");
                    break;
                case 16:
                    labels[x][y]->setStyleSheet("background:#ffcc99; border-radius:10");
                    break;
                case 32:
                    labels[x][y]->setStyleSheet("background:#ff9999; border-radius:10");
                    break;
                case 64:
                    labels[x][y]->setStyleSheet("background:#ff9966; border-radius:10");
                    break;
                case 128:
                    labels[x][y]->setStyleSheet("background:#ff6666; border-radius:10");
                    break;
                case 256:
                    labels[x][y]->setStyleSheet("background:#cc9966; border-radius:10");
                    break;
                case 512:
                    labels[x][y]->setStyleSheet("background:#cc3333; border-radius:10");
                    break;
                case 1024:
                    labels[x][y]->setStyleSheet("background:#cc0033; border-radius:10");
                    break;
                case 2048:
                    labels[x][y]->setStyleSheet("background:#ff0000; border-radius:10");
                    break;
                }
            }
        }
    }
}

#include <QApplication>
#include "gamewidget.h"
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    GameWidget gameWidget;
    gameWidget.show();
    return a.exec();
}

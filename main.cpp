#include <QApplication>
#include <QDebug>
#include <QString>
#include "source/Scales.h"
#include "widgets/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow m1;

    return QApplication::exec();
}

#include "lotterydraw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LotteryDraw w;
    w.show();

    return a.exec();
}

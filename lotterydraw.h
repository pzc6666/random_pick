#ifndef LOTTERYDRAW_H
#define LOTTERYDRAW_H

#include <QWidget>
#include <Qlist>
#include <QTime>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QMetaType>
#include <QMessageBox>
#include "mythread.h"

namespace Ui {
class LotteryDraw;
}

class LotteryDraw : public QWidget
{
    Q_OBJECT

public:
    explicit LotteryDraw(QWidget *parent = 0);
    ~LotteryDraw();
signals:
    void start(QList<int> m_list);
    void stop();
    void sendFilePath(QString filepath);
private slots:

    void on_select_file_clicked();

private:
    Ui::LotteryDraw *ui;
    QList<int> m_list;
};

#endif // LOTTERYDRAW_H

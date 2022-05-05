#ifndef GENERATE_H
#define GENERATE_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QString>
#include <QTime>
#include <QDebug>
#include <QFileDialog>
#include <QFile>


class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = 0);

protected:
    void run() override;

signals:
    void sendShow(QString str);

public slots:
    void recvList(QList<QString> m_list);
    void setStop();
private:
    QList<QString> list;
    bool flag;
};

class ReadFile : public QThread
{
    Q_OBJECT
public:
    explicit ReadFile(QObject *parent = 0);

protected:
    void run() override;

signals:
    void sendList(QList<QString> list);

public slots:
    void recvFilePath(QString filepath);

private:
    QString m_filepath;
};

#endif // GENERATE_H

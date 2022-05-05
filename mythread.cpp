#include "mythread.h"

Generate::Generate(QObject *parent) :  QThread(parent)
{

}

void Generate::run()
{
    qDebug() << "随机数线程：" << QThread::currentThreadId();
    flag=true;
    QTime time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    while(flag)
    {
        int n = qrand() % list.size();    //产生10以内的随机数
        emit sendShow(list[n]);
        QThread::msleep(100);
    }
}

void Generate::recvList(QList<QString> m_list)
{
    qDebug() << m_list.size();
    list=m_list;
}

void Generate::setStop()
{
    flag=false;
}

ReadFile::ReadFile(QObject *parent):  QThread(parent)
{

}

void ReadFile::run()
{
    qDebug() << "读文件线程：" << QThread::currentThreadId();
    QList<QString> list;
    QString line;
    qDebug() << m_filepath;
    QFile file(m_filepath);//构建文件对象，对文件做相关操作
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "打开文件失败！";
    }
    else
    {
        while(!file.atEnd())
        {
            line=file.readLine();
            line=line.simplified();
            list.append(line);
        }
        file.close();
    }
    emit sendList(list);
}

void ReadFile::recvFilePath(QString filepath)
{
    m_filepath=filepath;
}

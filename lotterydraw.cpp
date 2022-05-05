#include "lotterydraw.h"
#include "ui_lotterydraw.h"

LotteryDraw::LotteryDraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LotteryDraw)
{
    ui->setupUi(this);
    this->setWindowTitle("随机点名");
    qRegisterMetaType<QList<QString>>("QList<QString>");
    ReadFile *rf=new ReadFile;
    Generate *gen=new Generate;
    qDebug() << "主线程：" << QThread::currentThreadId();
    connect(this,&LotteryDraw::sendFilePath,rf,&ReadFile::recvFilePath);
    connect(ui->btn_pick,&QPushButton::clicked,this,[=](){
        QString filepath=ui->filename_text->text();
        if(filepath.size()==0)
        {
            QMessageBox::warning(this,"警告","未选择读取文件！");
        }
        else
        {
            emit sendFilePath(filepath);
            rf->start();
        }
    });
    connect(rf,&ReadFile::sendList,gen,&Generate::recvList);
    connect(rf,&ReadFile::sendList,this,[=](){
        gen->start();
    });
    connect(gen,&Generate::sendShow,this,[=](QString str){
        ui->pick_name->setText(str);
    });
    connect(ui->btn_stop,&QPushButton::clicked,gen,&Generate::setStop);

    connect(this, &LotteryDraw::destroyed, this, [=]()
        {
            gen->quit();
            gen->wait();
            gen->deleteLater();

            rf->quit();
            rf->wait();
            rf->deleteLater();
        });
}

LotteryDraw::~LotteryDraw()
{
    delete ui;
}

void LotteryDraw::on_select_file_clicked()
{
    QString filePath=QFileDialog::getOpenFileName();
    if(filePath.size()==0)
    {
        QMessageBox::warning(this,"选择文件","你选择的文件为空！");
    }
    else
    {
        ui->filename_text->setText(filePath);
    }
}

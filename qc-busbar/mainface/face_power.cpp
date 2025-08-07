#include "face_power.h"
#include "ui_face_power.h"

Face_Power::Face_Power(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Face_Power)
{
    ui->setupUi(this);
    mFirst = 1;
    initLayout();
    initWid();

}

Face_Power::~Face_Power()
{
    delete ui;
}

void Face_Power::initLayout()
{
    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit->setPalette(pl);

    QGridLayout *gridLayout = new QGridLayout(this->parentWidget());
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->addWidget(this);

    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void Face_Power::initWid()
{
    mDataWid = new Home_DataWid(ui->tabWidget);
    ui->tabWidget->addTab(mDataWid, "测试数据");

    mLineTabWid = new Home_LoopTabWid(ui->tabWidget);
    ui->tabWidget->addTab(mLineTabWid, "回路数据");

    mLoadWid = new Home_Loadwid(ui->tabWidget);
    ui->tabWidget->addTab(mLoadWid, "负载数据");

    ui->tabWidget->setCurrentIndex(0);
}

void Face_Power::TextSlot(QString str)
{
    QString str1 = QString::number(mFirst++) + "、"+ str;
    ui->textEdit->setText(str1);
}

void Face_Power::ClearText()
{
    mFirst = 1;
    ui->textEdit->clear();
    ui->label->setStyleSheet("");
}

void Face_Power::ImageSlot(int value)
{
    switch (value) {
    case 0:
        ui->label->setStyleSheet("QLabel{background-image: url(:/image/vol_test.jpg);}");
        break;
    case 1:
        ui->label->setStyleSheet("QLabel{background-image: url(:/image/ploa.jpg);}");
        break;
    case 2:
        ui->label->setStyleSheet("QLabel{background-image: url(:/image/cur_test.jpg);}");
        break;
    case 3:
        ui->label->setStyleSheet("QLabel{background-image: url(:/image/serial.jpg);}");
        break;
    case 4:
        ui->label->setStyleSheet("");
        break;
    case 5:
        ui->label->setStyleSheet("QLabel{background-image: url(:/image/isd_test.png);}");
        break;
    default:
        break;
    }
    // if(value == 1)
    // {
    //     QString str = tr("极性测试指示灯1和灯2亮");
    //     bool ret = MsgBox::information(this,str);
    // }
}

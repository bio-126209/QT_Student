#include "dialog.h"
#include<QHBoxLayout>    //水平布局
#include<QVBoxLayout>    //垂直布局

//创建界面控件
void Dialog::iniUI()
{
    //创建三个checkbox控件
    checkBoxUnderline = new QCheckBox(tr("Underline"));
    checkBoxItalic = new QCheckBox(tr("Italic"));
    checkBoxBold = new QCheckBox(tr("Bold"));


    //对Checkbox控件水平布局
    QHBoxLayout *HLayout1 = new QHBoxLayout;
    HLayout1->addWidget(checkBoxUnderline);
    HLayout1->addWidget(checkBoxItalic);
    HLayout1->addWidget(checkBoxBold);



    //创建三个radiobutton控件
    rBtnBalck = new QRadioButton(tr("Black"));
    rBtnBlue = new QRadioButton(tr("Blue"));
    rBtnRed = new QRadioButton(tr("Red"));


    //对RadioButton控件水平布局
    QHBoxLayout *HLayout2 = new QHBoxLayout;
    HLayout2->addWidget(rBtnBalck);
    HLayout2->addWidget(rBtnBlue);
    HLayout2->addWidget(rBtnRed);


    //创建一个plaintextedit控件,改变字体大小,写如内容。
    plainTxEdit = new QPlainTextEdit();
    QFont font = plainTxEdit->font();
    font.setPixelSize(20);
    plainTxEdit->setFont(font);
    plainTxEdit->setPlainText("Hello,world!");


    //创建三个Pushbutton控件
    btn_Ok = new QPushButton("Ok");
    btn_Cancel = new QPushButton("Cancel");
    btn_Close = new QPushButton("Close");


    //对pushbutton控件进行水平布局
    QHBoxLayout *HLayout3 = new QHBoxLayout;
    HLayout3->addStretch();    //添加弹簧
    HLayout3->addWidget(btn_Ok);
    HLayout3->addStretch();
    HLayout3->addWidget(btn_Cancel);
    HLayout3->addStretch();
    HLayout3->addWidget(btn_Close);
    HLayout3->addStretch();


    //创建整体的垂直布局
    QVBoxLayout *VLayout = new QVBoxLayout;
    VLayout->addLayout(HLayout1);
    VLayout->addLayout(HLayout2);
    VLayout->addWidget(plainTxEdit);
    VLayout->addLayout(HLayout3);
    setLayout(VLayout);
}

//实现控件信号与槽函数连接
void Dialog::iniSignalSlots()
{
    connect(btn_Ok,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btn_Close,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btn_Cancel,SIGNAL(clicked()),this,SLOT(close()));

    connect(checkBoxUnderline,SIGNAL(clicked(bool)),this,SLOT(on_checkUnderline(bool)));
    connect(checkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_checkItalic(bool)));
    connect(checkBoxBold,SIGNAL(clicked(bool)),this,SLOT(on_checkBold(bool)));

    connect(rBtnBalck,SIGNAL(clicked()),this,SLOT(on_rBtnColor()));
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(on_rBtnColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(on_rBtnColor()));
}

//控制文本是否下划线
void Dialog::on_checkUnderline(bool checked)
{
    QFont font = plainTxEdit->font();
    font.setUnderline(checked);
    plainTxEdit->setFont(font);
}

//控制文本字体是否倾斜
void Dialog::on_checkItalic(bool checked)
{
    QFont font = plainTxEdit->font();
    font.setItalic(checked);
    plainTxEdit->setFont(font);
}

//控制文本字体是否加粗
void Dialog::on_checkBold(bool checked)
{
    QFont font = plainTxEdit->font();
    font.setBold(checked);
    plainTxEdit->setFont(font);
}

//控制文本字体颜色
void Dialog::on_rBtnColor()
{
    QPalette plet=plainTxEdit->palette();
    if(rBtnBalck->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::black);
    }
    else if(rBtnBlue->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::blue);
    }
    else if(rBtnRed->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::red);
    }
    else
    {
        plet.setColor(QPalette::Text,Qt::black);
    }

    plainTxEdit->setPalette(plet);
}


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    iniUI();    //调用ui界面函数
    iniSignalSlots();    //调用函数实现控件功能;

}


Dialog::~Dialog()
{
}

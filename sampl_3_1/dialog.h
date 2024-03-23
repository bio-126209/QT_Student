#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QCheckBox>
#include<QRadioButton>
#include<QPushButton>
#include<QPlainTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QCheckBox *checkBoxUnderline;
    QCheckBox *checkBoxItalic;
    QCheckBox *checkBoxBold;

    QRadioButton *rBtnBalck;
    QRadioButton *rBtnBlue;
    QRadioButton *rBtnRed;

    QPlainTextEdit *plainTxEdit;

    QPushButton *btn_Ok;
    QPushButton *btn_Cancel;
    QPushButton *btn_Close;

    void iniUI();    //ui界面布局的函数
    void iniSignalSlots();    //button控件实现的函数，用于实现确认、取消、退出等功能

private slots:
    void on_checkUnderline(bool checked);
    void on_checkItalic(bool checked);
    void on_checkBold(bool checked);

    void on_rBtnColor();

};
#endif // DIALOG_H

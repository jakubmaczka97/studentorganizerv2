#ifndef SEECASHDIALOG_H
#define SEECASHDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QTableView>
#include <QPushButton>
class seecashdialog : public QDialog
{
    Q_OBJECT

public:
    explicit seecashdialog(QWidget *parent = nullptr);
    ~seecashdialog();
private slots:
    void on_loadButton_clicked();
private:
    QGridLayout *layoutsec3;
    QTableView *cashView;
    QPushButton *loadButton;
    QPushButton *closeButton;
    //Ui::seenotedialog *ui;
};

#endif // SEECASHDIALOG_H

#ifndef SEECALDIALOG_H
#define SEECALDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QTableView>
#include <QPushButton>


class seecaldialog : public QDialog
{
    Q_OBJECT

public:
    explicit seecaldialog(QWidget *parent = nullptr);
    ~seecaldialog();
private slots:
    void on_loadButton_clicked();
private:
    QGridLayout *layoutsec2;
    QTableView *calView;
    QPushButton *loadButton;
    QPushButton *closeButton;
};

#endif // SEECALDIALOG_H

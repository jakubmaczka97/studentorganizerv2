#ifndef SEENOTEDIALOG_H
#define SEENOTEDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QTableView>
#include <QPushButton>
class seenotedialog : public QDialog
{
    Q_OBJECT

public:
    explicit seenotedialog(QWidget *parent = nullptr);
    ~seenotedialog();
private slots:
    void on_loadButton_clicked();
private:
    QGridLayout *layoutsec;
    QTableView *noteView;
    QPushButton *loadButton;
    QPushButton *closeButton;
    //Ui::seenotedialog *ui;
};

#endif // SEENOTEDIALOG_H

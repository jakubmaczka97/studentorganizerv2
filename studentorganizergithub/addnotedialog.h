
#ifndef ADDNOTEDIALOG_H
#define ADDNOTEDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QtSql>
#include <QtDebug>
#include "mainwindow.h"

/*namespace Ui {
class addnotedialog;
}*/

class addnotedialog : public QDialog
{
    Q_OBJECT

public:

    explicit addnotedialog(QWidget *parent = nullptr);
    ~addnotedialog();
private slots:
    void on_addButton_clicked();
private:
    QWidget *dialog;
    QGridLayout *layout;
    QLabel *titleLabel;
    QLabel *contentLabel;
    QLabel *priorityLabel;
    QLineEdit *titleEdit;
    QLineEdit *contentEdit;
    QLineEdit *priorityEdit;
    QPushButton *addButton;
    QPushButton *clearButton;
    QLabel *sqlLabel;
    //Ui::addnotedialog *ui;
};

#endif // ADDNOTEDIALOG_H

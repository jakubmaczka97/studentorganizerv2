#ifndef REMINDER_H
#define REMINDER_H

#include <QDialog>
#include <QDate>
#include "mainwindow.h"

/*namespace Ui {
class reminder;
}*/

class reminder : public QDialog
{
    Q_OBJECT

public:
    explicit reminder(QWidget *parent = nullptr);
    ~reminder();
private slots:
    void loadData();
private:
    QGridLayout *remLay;
    QListView *remView;
    QPushButton *loadButton;
    QPushButton *closeButton;
    QDate *todayDate;
    QString *todayString;
    //Ui::reminder *ui;
};

#endif // REMINDER_H

//Created by Jakub Mączka 2019
//Copyright Jakub Mączka 2019

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QDate>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QtGui>
#include <Qt>
#include <QToolBar>
#include <QTableView>
#include <QHeaderView>
#include <QTabWidget>
#include <QFrame>
#include <QtSql>
#include <QDebug>
#include "addnotedialog.h"
#include "addcaldialog.h"
#include <QSystemTrayIcon>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase sogithub;
    void connClose()
    {
        sogithub.close();
        sogithub.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        QSqlDatabase sogithub=QSqlDatabase::addDatabase("QSQLITE");
        sogithub.setDatabaseName("C:/sqlite/sogithub.db");
        if(!sogithub.open()){
            qDebug()<<("Coś poszło nie tak :(");
            return false;
        }
        else{
            qDebug()<<("Wszystko działa");
            return true;
        }

    }

public:
    MainWindow();
private slots:
    void on_addNoteButton_clicked();
    void on_addCalButton_clicked();
    void on_addCashButton_clicked();
    void on_seeNoteButton_clicked();
    void on_seeCalButton_clicked();
    void on_seeCashButton_clicked();
    void openReminder();

private:
    //Main Window
    QWidget *mainWidget;
    QGridLayout *widgetLayout;
    //Sekcja Notatki
    QLabel *noteLabel;
    QPushButton *addNoteButton;
    QPushButton *seeNoteButton;
    //Sekcja Kalendarz
    QGridLayout *calLayout;
    QLabel *calLabel;
    QHBoxLayout *calButtons;
    QPushButton *addCalButton;
    QPushButton *seeCalButton;
    //Sekcja Budżet
    QLabel *cashLabel;
    QPushButton *addCashButton;
    QPushButton *seeCashButton;
    QPushButton *closeButton;
    QLabel *sqlLabel;
    QFrame *line;

    //Metody
    void createLine();
    void createMenu();

};
#endif

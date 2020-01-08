//Created by Jakub Mączka 2019
//Copyright Jakub Mączka 2019

#include "mainwindow.h"
#include "addnotedialog.h"
#include "addcaldialog.h"
#include "addcashdialog.h"
#include "seenotedialog.h"
#include "seecaldialog.h"
#include "seecashdialog.h"
#include "reminder.h"


MainWindow::MainWindow()
{
    setWindowTitle("Student Organizer GitHub v2");
    //setFixedSize(400, 720);

    mainWidget = new QWidget();
    widgetLayout = new QGridLayout();
    //Sekcja Notatki
    noteLabel = new QLabel ("Notatki");
    widgetLayout->addWidget(noteLabel,0,0,Qt::AlignCenter);
    //Przyciski Notatek
    addNoteButton = new QPushButton("Dodaj notatkę");
    seeNoteButton = new QPushButton("Wyświetl notatki");
    widgetLayout->addWidget(addNoteButton,1,0);
    widgetLayout->addWidget(seeNoteButton,2,0);
    //Slots Signals Notatki
    QObject::connect(addNoteButton, SIGNAL(clicked()), this, SLOT(on_addNoteButton_clicked()));
    QObject::connect(seeNoteButton, SIGNAL(clicked()), this, SLOT(on_seeNoteButton_clicked()));

    //Sekcja Kalendarz
    calLabel = new QLabel ("Kalendarz");
    widgetLayout->addWidget(calLabel,3,0,Qt::AlignCenter);
    //Przyciski Kalendarz
    addCalButton = new QPushButton("Dodaj wydarzenie");
    seeCalButton = new QPushButton("Wyświetl kalendarz");
    widgetLayout->addWidget(addCalButton,4,0);
    widgetLayout->addWidget(seeCalButton,5,0);
    //Slots Signals Kalendarz
    QObject::connect(addCalButton, SIGNAL(clicked()), this, SLOT(on_addCalButton_clicked()));
    QObject::connect(seeCalButton, SIGNAL(clicked()), this, SLOT(on_seeCalButton_clicked()));

    //Sekcja Budżet
    cashLabel = new QLabel ("Budżet");
    widgetLayout->addWidget(cashLabel,6,0,Qt::AlignCenter);
    //Przyciski Budżet

    addCashButton = new QPushButton("Dodaj wpis do budżetu");
    seeCashButton = new QPushButton("Wyświetl budżet");
    widgetLayout->addWidget(addCashButton,7,0);
    widgetLayout->addWidget(seeCashButton,8,0);
    //Slots Signals Kalendarz
    QObject::connect(addCashButton, SIGNAL(clicked()), this, SLOT(on_addCashButton_clicked()));
    QObject::connect(seeCashButton, SIGNAL(clicked()), this, SLOT(on_seeCashButton_clicked()));
    //Pomocnicze
    line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    widgetLayout->addWidget(line,9,0);
    closeButton =new QPushButton("Zamknij program");
    widgetLayout->addWidget(closeButton,10,0);
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    sqlLabel = new QLabel();
    widgetLayout->addWidget(sqlLabel,11,0);

    if(!connOpen())
        sqlLabel->setText("Błąd połaczenia z bazą danych");
    else
        sqlLabel->setText("Połączono z bazą danych");

    QTimer::singleShot(0, this, SLOT(openReminder()));
    mainWidget->setLayout(widgetLayout);
    setCentralWidget(mainWidget);
}
 void MainWindow::on_addNoteButton_clicked()
 {
    addnotedialog dialog;
     dialog.setModal(true);
     dialog.exec();
 }

 void MainWindow::on_seeNoteButton_clicked()
 {
     seenotedialog dialogsec;
     dialogsec.setModal(true);
     dialogsec.exec();
 }
 void MainWindow::on_addCalButton_clicked()
 {
     addcaldialog dialog2;
     dialog2.setModal(true);
     dialog2.exec();
 }

 void MainWindow::on_seeCalButton_clicked()
 {
     seecaldialog dialogsec2;
     dialogsec2.setModal(true);
     dialogsec2.exec();
 }
 void MainWindow::on_addCashButton_clicked()
 {
     addcashdialog dialog3;
     dialog3.setModal(true);
     dialog3.exec();
 }

 void MainWindow::on_seeCashButton_clicked()
 {
     seecashdialog dialogsec3;
     dialogsec3.setModal(true);
     dialogsec3.exec();
 }

 void MainWindow::openReminder()
 {
     reminder dialogrem;
     dialogrem.setModal(true);
     dialogrem.exec();
 }

/*void MainWindow::createLine() {
    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    noteLayout->addWidget(line,1,0);
    calLayout->addWidget(line,1,0);
    cashLayout->addWidget(line,1,0);
}*/

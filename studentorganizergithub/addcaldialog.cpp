#include "addcaldialog.h"
//#include "ui_addcaldialog.h"

addcaldialog::addcaldialog(QWidget *parent) :
    QDialog(parent)
{
    titleLabel = new QLabel("Tytuł Notatki: ");
    titleEdit = new QLineEdit();
    contentLabel = new QLabel("Treść Notatki: ");
    contentEdit = new QLineEdit();
    priorityLabel = new QLabel("Priorytet Notatki");
    priorityEdit = new QLineEdit();
    dateLabel = new QLabel("Data: ");
    dateEdit = new QDateEdit();
    timeLabel = new QLabel("Godzina: ");
    timeEdit = new QTimeEdit();
    addButton = new QPushButton("Dodaj");
    //clearButton = new QPushButton("Zamknij");
    sqlLabel = new QLabel();
    layout2 = new QGridLayout;
    layout2->addWidget(titleLabel, 0, 0);
    layout2->addWidget(titleEdit, 0, 1);
    layout2->addWidget(contentLabel, 1, 0);
    layout2->addWidget(contentEdit, 1, 1);
    layout2->addWidget(priorityLabel, 2, 0);
    layout2->addWidget(priorityEdit, 2, 1);
    layout2->addWidget(dateLabel, 3, 0);
    layout2->addWidget(dateEdit, 3, 1);
    layout2->addWidget(timeLabel, 3, 2);
    layout2->addWidget(timeEdit, 3, 3);
    layout2->addWidget(addButton, 4, 0);
    //layout2->addWidget(clearButton, 4, 1);
    layout2->addWidget(sqlLabel,5,0);
    setLayout(layout2);
    setWindowTitle("Dodaj Wydarzenie");

    MainWindow conn;
    if(!conn.connOpen())
        sqlLabel->setText("Błąd połaczenia z bazą danych");
    else
        sqlLabel->setText("Połączono z bazą danych");


    connect(addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
    //connect(clearButton, SIGNAL(clicked()), this, SLOT(close()));
}

void addcaldialog::on_addButton_clicked()
{
    MainWindow conn;
    QString title,content,priority;

    title=titleEdit->text();
    priority=priorityEdit->text();
    content=contentEdit->text();
    QDate date = dateEdit->date();
    QString dates = date.toString("yyyy-MM-dd");
    QTime time = timeEdit->time();
    QString times = time.toString("hh:mm");



    if(!conn.connOpen()){
        qDebug()<<"Niepodłączono do bazy";
        return;
    }

    conn.connOpen();
    QSqlQuery addcal;
    addcal.prepare("insert into calendar (title,content,priority,date,time) values ('"+title+"','"+content+"','"+priority+"','"+dates+"','"+times+"')");

    if(addcal.exec())
    {
       QMessageBox::critical(this,tr("Zapisano"),tr("Zapisano do bazy danych"));
       conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),addcal.lastError().text());
    }
}

addcaldialog::~addcaldialog()
{
    //delete ui;
}

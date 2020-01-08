#include "addcashdialog.h"
//#include "ui_addcashdialog.h"

addcashdialog::addcashdialog(QWidget *parent) :
    QDialog(parent)
{
    titleLabel = new QLabel("Tytuł Notatki: ");
    titleEdit = new QLineEdit();
    dateLabel = new QLabel("Data: ");
    dateEdit = new QDateEdit();
    priceLabel = new QLabel("Kwota: ");
    priceEdit = new QLineEdit();
    addButton = new QPushButton("Dodaj");
    //clearButton = new QPushButton("Zamknij");
    sqlLabel = new QLabel;
    layout3 = new QGridLayout;
    layout3->addWidget(titleLabel, 0, 0);
    layout3->addWidget(titleEdit, 0, 1);
    layout3->addWidget(dateLabel, 1, 0);
    layout3->addWidget(dateEdit, 1, 1);
    layout3->addWidget(priceLabel, 2, 0);
    layout3->addWidget(priceEdit, 2, 1);
    layout3->addWidget(addButton, 3, 0);
    //layout3->addWidget(clearButton, 3, 1);
    layout3->addWidget(sqlLabel, 4, 0);
    setLayout(layout3);
    setWindowTitle("Dodaj Wpis Do Budżetu");

    MainWindow conn;
    if(!conn.connOpen())
        sqlLabel->setText("Błąd połaczenia z bazą danych");
    else
        sqlLabel->setText("Połączono z bazą danych");

    connect(addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
    //connect(clearButton, SIGNAL(clicked()), this, SLOT(close()));
}

void addcashdialog::on_addButton_clicked()
{
    MainWindow conn;
    QString title, price;

    title=titleEdit->text();
    //price=priceEdit->text();
    price=priceEdit->text();
    QDate date = dateEdit->date();
    QString dates = date.toString("yyyy-MM-dd");



    if(!conn.connOpen()){
        qDebug()<<"Niepodłączono do bazy";
        return;
    }

    conn.connOpen();
    QSqlQuery addcash;
    addcash.prepare("insert into cashh (title,price,date) values ('"+title+"','"+price+"','"+dates+"')");

    if(addcash.exec())
    {
       QMessageBox::critical(this,tr("Zapisano"),tr("Zapisano do bazy danych"));
       conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),addcash.lastError().text());
    }
}
addcashdialog::~addcashdialog()
{
    //delete ui;
}


#include "addnotedialog.h"
//#include "ui_addnotedialog.h"

addnotedialog::addnotedialog(QWidget *parent) :
    QDialog(parent)
{
    titleLabel = new QLabel("Tytuł Notatki: ");
    titleEdit = new QLineEdit();
    contentLabel = new QLabel("Treść Notatki: ");
    contentEdit = new QLineEdit();
    priorityLabel = new QLabel("Priorytet Notatki");
    priorityEdit = new QLineEdit();
    addButton = new QPushButton("Dodaj");
    //clearButton = new QPushButton("Zamknij");
    sqlLabel = new QLabel();
    layout = new QGridLayout;
    layout->addWidget(titleLabel, 0, 0);
    layout->addWidget(titleEdit, 0, 1);
    layout->addWidget(contentLabel, 1, 0);
    layout->addWidget(contentEdit, 1, 1);
    layout->addWidget(priorityLabel, 2, 0);
    layout->addWidget(priorityEdit, 2, 1);
    layout->addWidget(addButton, 3, 0);
    //layout->addWidget(clearButton, 3, 1);
    layout->addWidget(sqlLabel,4,0);
    setLayout(layout);
    setWindowTitle("Dodaj Notatkę");

    MainWindow conn;
    if(!conn.connOpen())
        sqlLabel->setText("Błąd połaczenia z bazą danych");
    else
        sqlLabel->setText("Połączono z bazą danych");

    connect(addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
    //connect(clearButton, SIGNAL(clicked()), this, SLOT(close()));
}

void addnotedialog::on_addButton_clicked()
{
    MainWindow conn;
    QString title,content,priority;
    title=titleEdit->text();
    priority=priorityEdit->text();
    content=contentEdit->text();
    if(!conn.connOpen()){
        qDebug()<<"Niepodłączono do bazy";
        return;
    }

    conn.connOpen();
    QSqlQuery addnote;
    addnote.prepare("insert into notes (title,content,priority) values ('"+title+"','"+content+"','"+priority+"')");

    if(addnote.exec())
    {
       QMessageBox::critical(this,tr("Zapisano"),tr("Zapisano do bazy danych"));
       conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),addnote.lastError().text());
    }
}

addnotedialog::~addnotedialog()
{
    //delete ui;
}

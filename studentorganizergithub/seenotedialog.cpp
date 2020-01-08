#include "seenotedialog.h"
//#include "ui_seenotedialog.h"
#include <QDebug>

seenotedialog::seenotedialog(QWidget *parent) :
    QDialog(parent)
{
    layoutsec = new QGridLayout();
    noteView = new QTableView();
    loadButton = new QPushButton("Wczytaj notatki");
    closeButton = new QPushButton("Zamknij");
    layoutsec->addWidget(noteView,0,0);
    layoutsec->addWidget(loadButton,1,0);
    layoutsec->addWidget(closeButton,1,1);
    setLayout(layoutsec);
    setWindowTitle("Twoje Notatki");
    connect(loadButton, SIGNAL(clicked()), this, SLOT(on_loadButton_clicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

void seenotedialog::on_loadButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *seenote = new QSqlQuery(conn.sogithub);

    seenote->prepare("select * from notes");
    seenote->exec();
    modal->setQuery(*seenote);
    noteView->setModel(modal);
    conn.connClose();
    //qDebug<<(model->rowCount());

}
seenotedialog::~seenotedialog()
{
    //delete ui;
}

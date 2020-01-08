#include "seecashdialog.h"
//#include "ui_seecashdialog.h"
#include <QDebug>

seecashdialog::seecashdialog(QWidget *parent) :
    QDialog(parent)
{
    layoutsec3 = new QGridLayout();
    cashView = new QTableView();
    loadButton = new QPushButton("Wczytaj budżet");
    closeButton = new QPushButton("Zamknij");
    layoutsec3->addWidget(cashView,0,0);
    layoutsec3->addWidget(loadButton,1,0);
    layoutsec3->addWidget(closeButton,1,1);
    setLayout(layoutsec3);
    setWindowTitle("Twój Budżet");
    connect(loadButton, SIGNAL(clicked()), this, SLOT(on_loadButton_clicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

void seecashdialog::on_loadButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *seecash = new QSqlQuery(conn.sogithub);

    seecash->prepare("select * from cashh");
    seecash->exec();
    modal->setQuery(*seecash);
    cashView->setModel(modal);
    conn.connClose();
    //qDebug<<(model->rowCount());

}
seecashdialog::~seecashdialog()
{
    //delete ui;
}

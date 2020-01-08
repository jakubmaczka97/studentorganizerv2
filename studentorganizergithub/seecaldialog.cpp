#include "seecaldialog.h"
//#include "ui_seecaldialog.h"

seecaldialog::seecaldialog(QWidget *parent) :
    QDialog(parent)
{
    layoutsec2 = new QGridLayout();
    calView = new QTableView();
    loadButton = new QPushButton("Wczytaj kalendarz");
    closeButton = new QPushButton("Zamknij");
    layoutsec2->addWidget(calView,0,0);
    layoutsec2->addWidget(loadButton,1,0);
    layoutsec2->addWidget(closeButton,1,1);
    setLayout(layoutsec2);
    setWindowTitle("Twój Kalendarz");
    connect(loadButton, SIGNAL(clicked()), this, SLOT(on_loadButton_clicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

void seecaldialog::on_loadButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *seenote = new QSqlQuery(conn.sogithub);

    seenote->prepare("select * from calendar");
    seenote->exec();
    modal->setQuery(*seenote);
    calView->setModel(modal);
    conn.connClose();
    //qDebug<<(model->rowCount());

}
seecaldialog::~seecaldialog()
{
}

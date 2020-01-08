#include "reminder.h"
#include "ui_reminder.h"

reminder::reminder(QWidget *parent) :
    QDialog(parent)
{
    remLay = new QGridLayout();
    remView = new QListView();
    closeButton = new QPushButton("Zamknij");
    remLay->addWidget(remView,0,0);
    remLay->addWidget(closeButton,1,0);
    setLayout(remLay);
    setWindowTitle("Przypominajka!");
    QTimer::singleShot(0, this, SLOT(loadData()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

void reminder::loadData()
{
    QString today;
    QDate todayDate = QDate::currentDate();
    today = todayDate.toString("yyyy-MM-dd");
    qDebug() << (today);

    MainWindow conn;
    QSqlQueryModel *modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *seenote = new QSqlQuery(conn.sogithub);

    seenote->prepare("select title from calendar where date=:today");
    seenote->bindValue(":today",today);
    seenote->exec();
    modal->setQuery(*seenote);
    remView->setModel(modal);
    conn.connClose();
}

reminder::~reminder()
{
    //delete ui;
}

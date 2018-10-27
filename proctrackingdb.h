#ifndef PROCTRACKINGDB_H
#define PROCTRACKINGDB_H

#include "QtSql/QtSql"
#include <qsqlquery.h>
#include "QString"
#include <QtSql/QSqlDatabase>
#include "QMessageBox"

class ProcTrackingDB
{
public:
    ProcTrackingDB();
    QString ConnectDataBase(bool Open);
    QString DisConnectDataBase(bool close);
    QStringList Tables();
    QString GetMyDbaseName();
   QSqlDatabase *MyDataBase;
   QString DBstatus();
   QString CurrentStatus;

private:
   QString MyDbaseName;



};

#endif // PROCTRACKINGDB_H

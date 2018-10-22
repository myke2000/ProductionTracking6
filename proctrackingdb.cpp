#include "proctrackingdb.h"

ProcTrackingDB::ProcTrackingDB()
{
    MyDataBase = new QSqlDatabase();
    *MyDataBase = QSqlDatabase::addDatabase("QSQLITE");
    MyDbaseName="./Tracking.sqldb";
   MyDataBase->setDatabaseName("./Tracking.sqldb");
}

QString ProcTrackingDB::DisConnectDataBase(bool close)
{
    QString ErrorConnect=MyDataBase->lastError().text();
    if(close==true)
    {
        if(MyDataBase->isOpen())
        {
            MyDataBase->close();
            MyDataBase->removeDatabase("QSQLITE");


            return "Database Closed";
        }
        else
        {
            return "No open Database";
        }
    }
    return ErrorConnect;
}

QString ProcTrackingDB::ConnectDataBase(bool Open )
{
    QString ErrorConnect=MyDataBase->lastError().text();


    int count=0;

    if(Open==true)
    {
        MyDataBase->open();
        if(MyDataBase->isOpen()!=true)
        {
            CurrentStatus="Not Connected";
             return ErrorConnect;
        }
        else
        {
            CurrentStatus="Connected";
            return "Connected";
        }

    }
    else if(MyDataBase->isDriverAvailable("QSQLITE")==true)
    {
        return "Driver Ready";
    }
    else if(MyDataBase->isDriverAvailable("QSQLITE")==false)
    {
        return "Driver Not Installed";

    }
    else
    {
        QStringList LoadedDrivers= QSqlDatabase::drivers();

        return LoadedDrivers.at(count);
    }
    //return ErrorConnect;

}

QString ProcTrackingDB::DBstatus()
{

}

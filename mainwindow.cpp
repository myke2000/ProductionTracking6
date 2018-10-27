#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "proctrackingdb.h"
#include <QFile>
#include <QMessageBox>
#include <firsttimesetup.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    GetInitFiles();

    ProcTrackingDB Production;

    Production.ConnectDataBase(true);
    ui->statusBar->showMessage(Production.CurrentStatus);

    ui->Recv_Button->setChecked(true);
    Button_Status=Receiving;
    Current_Button();
    ui->Shipping_Frame->hide();
    ui->Traveler_Frame->hide();
    ui->CurrentDate_Edit->setDate(QDate::currentDate());

}

void MainWindow::Current_Button()
{
    if(Button_Status==Receiving)
    {
        ui->Recv_Frame->show();
        ui->Traveler_Frame->hide();
        ui->Shipping_Frame->hide();
        ui->Proc_Stat_Frame->show();
        ui->Recv_Button->setChecked(true);
        ui->Trav_button->setChecked(false);
        ui->Ship_Button->setChecked(false);
        ui->Report_Button->setChecked(false);
        Button_Status=Receiving;
    }
    else if(Button_Status==Build)
    {
        ui->Recv_Frame->hide();
        ui->Traveler_Frame->show();
        ui->Shipping_Frame->hide();
        ui->Proc_Stat_Frame->show();
        ui->Recv_Button->setChecked(false);
        ui->Trav_button->setChecked(true);
        ui->Ship_Button->setChecked(false);
        ui->Report_Button->setChecked(false);
        Button_Status=Build;
    }
    else if(Button_Status==Ship)
    {
        ui->Recv_Frame->hide();
        ui->Traveler_Frame->hide();
        ui->Shipping_Frame->show();
        ui->Proc_Stat_Frame->show();
        ui->Recv_Button->setChecked(false);
        ui->Trav_button->setChecked(false);
        ui->Ship_Button->setChecked(true);
        ui->Report_Button->setChecked(false);
        Button_Status=Ship;
    }
    else if(Button_Status==Report)
    {
        ui->Recv_Frame->hide();
        ui->Traveler_Frame->hide();
        ui->Shipping_Frame->hide();
        ui->Proc_Stat_Frame->hide();
        ui->Recv_Button->setChecked(false);
        ui->Trav_button->setChecked(false);
        ui->Ship_Button->setChecked(false);
        ui->Report_Button->setChecked(true);
        Button_Status=Report;
    }
    else
    {

    }
}

void MainWindow::on_Recv_Button_clicked()
{
    Button_Status=Receiving;
    Current_Button();

}

void MainWindow::on_Trav_button_clicked()
{
    Button_Status=Build;
    Current_Button();
}

void MainWindow::on_Ship_Button_clicked()
{
    Button_Status=Ship;
    Current_Button();
}

void MainWindow::on_Report_Button_clicked()
{
    Button_Status=Report;
    Current_Button();

}

void MainWindow::About()
{

}

void MainWindow::newFile()
{

}

void MainWindow::Exitpgm()
{
    close();
}

void MainWindow::GetInitFiles()
{
    QString CreateConfigFiles;
    CreateConfigFiles = "ProductionTrackingDataBase.sqldb ;";
    QFile ConfigFiles;
    ConfigFiles.setFileName("Config.csv");
    if(!ConfigFiles.exists())
    {
        FirstTimeSetup StartNewSetup;
        if(StartNewSetup.exec()==1)
        {

           ConfigFiles.open( QFile::WriteOnly);
           QTextStream file(&ConfigFiles);
           file << "./ProductionTrackingDataBase.sqldb ;";
           ConfigFiles.close();


    }
    else
    {
        QMessageBox::warning(this,"File Found", "File Found");
    }


    if(!ConfigFiles.open(QFile::ReadWrite | QFile::Append))
    {

    }
    else
    {

    }


}
}

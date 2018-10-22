#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "proctrackingdb.h"

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

    ProcTrackingDB Production;

    Production.ConnectDataBase(true);
    ui->statusBar->showMessage(Production.CurrentStatus);

    ui->Recv_Button->setChecked(true);
    Button_Status=0;
    Current_Button();
    ui->Shipping_Frame->hide();
    ui->Traveler_Frame->hide();
    ui->CurrentDate_Edit->setDate(QDate::currentDate());

}

void MainWindow::Current_Button()
{
    if(Button_Status==0)
    {
        ui->Recv_Frame->show();
        ui->Traveler_Frame->hide();
        ui->Shipping_Frame->hide();
        ui->Proc_Stat_Frame->show();
        ui->Recv_Button->setChecked(true);
        ui->Trav_button->setChecked(false);
        ui->Ship_Button->setChecked(false);
        ui->Report_Button->setChecked(false);
        Button_Status=0;
    }
    else if(Button_Status==1)
    {
        ui->Recv_Frame->hide();
        ui->Traveler_Frame->show();
        ui->Shipping_Frame->hide();
        ui->Proc_Stat_Frame->show();
        ui->Recv_Button->setChecked(false);
        ui->Trav_button->setChecked(true);
        ui->Ship_Button->setChecked(false);
        ui->Report_Button->setChecked(false);
        Button_Status=1;
    }
    else if(Button_Status==2)
    {
        ui->Recv_Frame->hide();
        ui->Traveler_Frame->hide();
        ui->Shipping_Frame->show();
        ui->Proc_Stat_Frame->show();
        ui->Recv_Button->setChecked(false);
        ui->Trav_button->setChecked(false);
        ui->Ship_Button->setChecked(true);
        ui->Report_Button->setChecked(false);
        Button_Status=2;
    }
    else if(Button_Status==3)
    {
        ui->Recv_Frame->hide();
        ui->Traveler_Frame->hide();
        ui->Shipping_Frame->hide();
        ui->Proc_Stat_Frame->hide();
        ui->Recv_Button->setChecked(false);
        ui->Trav_button->setChecked(false);
        ui->Ship_Button->setChecked(false);
        ui->Report_Button->setChecked(true);
        Button_Status=3;
    }
    else
    {

    }
}

void MainWindow::on_Recv_Button_clicked()
{
    Button_Status=0;
    Current_Button();

}

void MainWindow::on_Trav_button_clicked()
{
    Button_Status=1;
    Current_Button();
}

void MainWindow::on_Ship_Button_clicked()
{
    Button_Status=2;
    Current_Button();
}

void MainWindow::on_Report_Button_clicked()
{
    Button_Status=3;
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

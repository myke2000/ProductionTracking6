#include "firsttimesetup.h"
#include "ui_firsttimesetup.h"
#include <QFileDialog>
#include <mainwindow.h>

FirstTimeSetup::FirstTimeSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstTimeSetup)
{
    ui->setupUi(this);
}

FirstTimeSetup::~FirstTimeSetup()
{
    delete ui;
}

void FirstTimeSetup::on_BrowseButton_clicked()
{
    QStringList SelectedFile;
    MainWindow test;

   // FileName=SelectedFile.at(0);


    QFileDialog FindDataBase(this);
    FindDataBase.setFileMode(QFileDialog::AnyFile);
    FindDataBase.setViewMode(QFileDialog::Detail);
    FindDataBase.setNameFilter("*.sqldb");
    /*if(FindDataBase.show())
    {
        SelectedFile=FindDataBase.selectedFiles();
        test.FileLocation=SelectedFile.at(0);

        ui->lineEdit->setText(test.FileLocation);
    }
    else
    {
        SelectedFile=FindDataBase.selectedFiles();
        test.FileLocation=SelectedFile.at(0);
        ui->lineEdit->setText(test.FileLocation);
    }
    */
}



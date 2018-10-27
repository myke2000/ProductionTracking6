#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <firsttimesetup.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Init();
    void Current_Button();
    enum {
        Receiving,
        Build,
        Ship,
        Report
    }  Button_Status;
    void GetInitFiles();
    QString FileLocation;
    QString SelectedFileName;


private slots:
    void on_Recv_Button_clicked();

    void on_Trav_button_clicked();

    void on_Ship_Button_clicked();

    void on_Report_Button_clicked();

    void newFile();
    void Exitpgm();
    void About();

private:
    Ui::MainWindow *ui;
    QStringList InitFiles;

};

#endif // MAINWINDOW_H

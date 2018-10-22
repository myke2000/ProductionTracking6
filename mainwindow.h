#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    int Button_Status;

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
};

#endif // MAINWINDOW_H

#ifndef FIRSTTIMESETUP_H
#define FIRSTTIMESETUP_H

#include <QDialog>



namespace Ui {
class FirstTimeSetup;
}

class FirstTimeSetup : public QDialog
{
    Q_OBJECT

public:
    explicit FirstTimeSetup(QWidget *parent = nullptr);
    ~FirstTimeSetup();


private slots:
    void on_BrowseButton_clicked();

private:
    Ui::FirstTimeSetup *ui;
};

#endif // FIRSTTIMESETUP_H

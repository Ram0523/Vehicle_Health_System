#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <api.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_FilterButton_clicked();
    void on_FluidButton_clicked();
    void FilterValueChange();
    void FluidValueChange();
    void load(QString type);
    void loadStatus(int row, int column, QString status,QString type);

private:
    Ui::MainWindow *ui=nullptr;
    api* ap=nullptr;
    QTimer* timer=nullptr;
    bool check=0;
};
#endif // MAINWINDOW_H

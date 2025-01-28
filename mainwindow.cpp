#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QHBoxLayout"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    ap=new api;
    QHeaderView *horizontalHeader = ui->FilterTable->horizontalHeader();
    horizontalHeader->setStyleSheet("background-color: #ffffff; color: #000000;");

    QHeaderView *verticalHeader = ui->FilterTable->verticalHeader();
    verticalHeader->setStyleSheet("background-color: #ffffff; color: #000000;");

    load("fluid");


    timer = new QTimer();

    timer->setInterval(1000);
    timer->setSingleShot(false);


    connect(timer, &QTimer::timeout,this, &MainWindow::FilterValueChange);

    timer->start();

}


void MainWindow::load(QString type){
    if(type=="filter"){
    std::vector<Filter_details*> filterList = Filter_details::FilterList;

    int rowsCount = filterList.size();
    ui->FilterTable->setRowCount(rowsCount);


    for(int i=0; i<rowsCount; i++){
        QTableWidgetItem *filterListItem =  new QTableWidgetItem(filterList[i]->getName());
        filterListItem->setTextAlignment(Qt::AlignCenter);
        ui->FilterTable->setItem(i,0,filterListItem);
        QDate currentDate = filterList[i]->getCurrentDate();
        QString dateString = currentDate.toString("dd-MM-yyyy");

        QTableWidgetItem *dateTableItem = new QTableWidgetItem(dateString);
        dateTableItem->setTextAlignment(Qt::AlignCenter);
        ui->FilterTable->setItem(i,2,dateTableItem);

        loadStatus(i, 1, "good","filter");
    }
    }
    else if(type=="fluid"){
        std::vector<Fluid_details*> fluidList = Fluid_details::FluidList;

        int rowsCount = fluidList.size();
        ui->FluidTable->setRowCount(rowsCount);


        for(int i=0; i<rowsCount; i++){
            QTableWidgetItem *fluidListItem =  new QTableWidgetItem(fluidList[i]->getName());
            fluidListItem->setTextAlignment(Qt::AlignCenter);
            ui->FluidTable->setItem(i,0,fluidListItem);
            QDate currentDate = fluidList[i]->getCurrentDate();
            QString dateString = currentDate.toString("dd-MM-yyyy");

            QTableWidgetItem *dateTableItem = new QTableWidgetItem(dateString);
            dateTableItem->setTextAlignment(Qt::AlignCenter);
            ui->FluidTable->setItem(i,2,dateTableItem);

            loadStatus(i, 1, "good","fluid");
        }
    }


}

void MainWindow::FilterValueChange(){


    std::vector<Filter_details*>& filterList = Filter_details::FilterList;
    for(int i=0; i<filterList.size(); i++){
        filterList[i] = filterList[i]->setStatus(i+1);
        int healthLevel = filterList[i]->getStatus();
        // qDebug()<<healthLevel;

        if(healthLevel > 80) loadStatus(i, 1, "good","filter");
        else if(healthLevel >= 50 && healthLevel <= 80) loadStatus(i, 1, "warning","filter");
        else loadStatus(i, 1, "critical","filter");
    }


}

void MainWindow::FluidValueChange(){


    std::vector<Fluid_details*>& fluidList = Fluid_details::FluidList;
    for(int i=0; i<fluidList.size(); i++){
        fluidList[i] = fluidList[i]->setStatus(i+1);
        int healthLevel = fluidList[i]->getStatus();
        // qDebug()<<healthLevel;

        if(healthLevel > 80) loadStatus(i, 1, "good","fluid");
        else if(healthLevel >= 50 && healthLevel <= 80) loadStatus(i, 1, "warning","fluid");
        else loadStatus(i, 1, "critical","fluid");
    }

}

void MainWindow::loadStatus(int row, int column, QString status,QString type){
    QWidget *widget = new QWidget();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QLabel *label1 = new QLabel();
    QLabel *label2 = new QLabel();
    hBoxLayout->addWidget(label1);
    hBoxLayout->addWidget(label2);
    widget->setLayout(hBoxLayout);

    if(type=="filter") {

        ui->FilterTable->setCellWidget(row, column, widget);
    }
    else if(type=="fluid"){
        ui->FluidTable->setCellWidget(row, column, widget);
    }

    int width = 30;
    int height = 30;

    label1->setFixedSize(width, height);

    if(status == "good"){
        QPixmap pixmap(":/Downloads/GOOD.jpeg");
        label2->setText("Looks Good");
        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }

    if(status == "warning"){
        QPixmap pixmap(":/Downloads/CRITICAL.jpeg");
        label2->setText("Warning !!!");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }

    if(status == "critical"){
        QPixmap pixmap(":/Downloads/WARNING.jpeg");
        label2->setText("Critical Problem !!!");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FilterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    if(check==0){
        load("filter");
        connect(timer, &QTimer::timeout,this, &MainWindow::FluidValueChange);
        check=1;
    }
}


void MainWindow::on_FluidButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);

}


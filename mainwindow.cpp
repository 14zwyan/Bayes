#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<string>
#include<vector>

#include<QString>

#include"bayes.h"

using std::string; using std::vector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName=ui->lineEdit_fileName->text();

    Bayes algo(1,fileName.toStdString());

    int size=algo.GetDataNumber();

    for(unsigned int i=0; i != size; ++i)
    {
        string data=algo.GetData(i);
        QString temp=QString::fromStdString(data);
        ui->textBrowser_data->append(temp);
    }

}

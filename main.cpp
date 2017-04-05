#include "mainwindow.h"
#include <QApplication>


#include<vector>

#include"bayes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Bayes algo;
    std::vector<double> test_data={6,130,8};

    std::cout<<algo.Classify(test_data)<<std::endl;

    MainWindow w;
    w.show();

    return a.exec();
}

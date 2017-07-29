#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <cstdlib>
#include <ctime>

using std::string;
using std::tuple;
using std::vector;
using std::fstream;
using std::get;

typedef tuple<string, string, string> s3tuple;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand( time( NULL ) );
    ui->setupUi(this);
    ui->label_3->hide();
    fstream file;
    file.open("answers.txt", std::ios::in);

    if (file.good())
    {
        string one, two, three;
        while (!file.eof())
        {
            getline(file, one);
            getline(file, two);
            getline(file, three);
            data.push_back(s3tuple(one,two,three));
        }
    }
    file.close();
    country = "polska";
    capital = "warszawa";
    image->load("pl.png");
    ui->displayLabel->setPixmap(QPixmap::fromImage(*image));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_check_clicked()
{
    if (ui->countryName->toPlainText().toLower() == country && ui->capitalName->toPlainText().toLower() == capital)
    {
        if (data.size() > 0)
        {
            int random = rand()%data.size();
            image->load(QString::fromStdString(get<0>(data.at(random))));
            country = QString::fromStdString(get<1>(data.at(random)));
            capital = QString::fromStdString(get<2>(data.at(random)));
            ui->displayLabel->setPixmap(QPixmap::fromImage(*image));
            data.erase(data.begin()+random);
        }
        else
        {
            ui->label_3->show();
        }
    }

}

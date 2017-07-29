#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QImage>
#include <vector>
#include <string>
#include <tuple>

using std::string;
using std::tuple;
using std::vector;

typedef tuple<string, string, string> s3tuple;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    vector<s3tuple> data;
    QImage *image = new QImage;
    QString capital, country;

private slots:
    void on_check_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

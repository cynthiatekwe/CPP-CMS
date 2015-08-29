#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <homeview.h>
#include <string>
#include <QString>
#include <QUrl>

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
    if(4+2 == 8){
        QMessageBox::information(this,tr("ERROR REPORT"),tr("Wrong Answer reported"));
    }
    else
        QMessageBox::critical(this,tr("ERROR REPORT"),tr("Wrong Answer reported"));

    ui->web->setText(QUrl("https://www.facebook.com/"));
}

void MainWindow::on_MainWindow_destroyed()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    homeView* win = new homeView;
    win->show();

}

void MainWindow::on_pushButton_3_clicked()
{
    QString username,password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    if(username == password){
        QMessageBox::information(this,tr("LOGIN VALID"),tr("Match Found"));
    }
    else
        QMessageBox::critical(this,tr("ERROR REPORT"),tr("Wrong Login reported"));
}

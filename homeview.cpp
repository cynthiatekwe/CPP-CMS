#include "homeview.h"
#include "ui_homeview.h"


homeView::homeView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::homeView)
{
    ui->setupUi(this);
}

homeView::~homeView()
{
    delete ui;
}

void homeView::on_pushButton_clicked()
{
    delete this;
}

void homeView::on_pushButton_2_clicked()
{

}

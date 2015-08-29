#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QMainWindow>

namespace Ui {
class homeView;
}

class homeView : public QMainWindow
{
    Q_OBJECT

public:
    explicit homeView(QWidget *parent = 0);
    ~homeView();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::homeView *ui;
};

#endif // HOMEVIEW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bibliocontroller.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class AddType : int
{
    Book = 0,
    Bd,
    Author
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();

    void on_addTypeComboBox_currentIndexChanged(int index);

    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    BiblioController* m_controller;
};
#endif // MAINWINDOW_H

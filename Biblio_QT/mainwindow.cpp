#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_controller = new BiblioController(this);
    // ui->treeView->setModel(m_controller->getModel());
    // ui->treeView->setRootIndex(m_controller->getModel()->index(0, 0));

    // connect(ui->addBookButton, &QPushButton::clicked, this, &MainWindow::on_addBookButton_clicked);
    // connect(ui->removeBookButton, &QPushButton::clicked, this, &MainWindow::on_removeBookButton_clicked);
    // connect(ui->addAuthorButton, &QPushButton::clicked, this, &MainWindow::on_addAuthorButton_clicked);
    // connect(ui->removeAuthorButton, &QPushButton::clicked, this, &MainWindow::on_removeAuthorButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    switch (addTypeComboBox->currentIndex())
    {
    case AddType::Book:
        break;
    
    case AddType::Bd:
        break;

    case AddType::Author:
        break;

    default:
        break;
    }
}

// void MainWindow::on_addBookButton_clicked()
// {
//     QString title = ui->bookTitleEdit->text();
//     QString author = ui->authorNameEdit->text();
//     m_controller->addBook(title, author);
// }

// void MainWindow::on_removeBookButton_clicked()
// {
//     QString title = ui->bookTitleEdit->text();
//     m_controller->removeBook(title);
// }

// void MainWindow::on_addAuthorButton_clicked()
// {
//     QString name = ui->authorNameEdit->text();
//     m_controller->addAuthor(name);
// }

// void MainWindow::on_removeAuthorButton_clicked()
// {
//     QString name = ui->authorNameEdit->text();
//     m_controller->removeAuthor(name);
// }
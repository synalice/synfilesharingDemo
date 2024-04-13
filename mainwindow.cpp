#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>

 #include <QFileDialog>
 #include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Добавление файлов
    connect(
        ui->selectFilesButton, &QPushButton::clicked,
        this, &MainWindow::selectFiles
    );

    // Удаление файлов
    connect(
        ui->selectedFiles, &QListWidget::itemDoubleClicked,
        this, &MainWindow::deleteClickedItem
    );


}

void MainWindow::selectFiles() {
    QList<QString> fileNames = QFileDialog::getOpenFileNames();
    ui->selectedFiles->addItems(fileNames);
}

void MainWindow::deleteClickedItem(QListWidgetItem *item) {
    ui->selectedFiles->takeItem(ui->selectedFiles->row(item));
}

MainWindow::~MainWindow()
{
    delete ui;
}

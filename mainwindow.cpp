#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <vector>

 #include <QFileDialog>
 #include <QListWidget>

#include <synfilesharing/synfilesharing.h>

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

    // Отправка файлов
    connect(
        ui->sendFilesButton, &QPushButton::clicked,
        this, &MainWindow::sendFiles
    );
}

void MainWindow::selectFiles() {
    QList<QString> fileNames = QFileDialog::getOpenFileNames();
    ui->selectedFiles->addItems(fileNames);
}

void MainWindow::deleteClickedItem(QListWidgetItem *item) {
    ui->selectedFiles->takeItem(ui->selectedFiles->row(item));
}

void MainWindow::sendFiles() {
    std::unique_ptr<synfs::IClient> client = synfs::makeClient().build();

    std::vector<std::string> files;
    for (int i = 0; i < ui->selectedFiles->count(); i++) {
        files.push_back(ui->selectedFiles->item(i) ->text().toStdString());
    }

    client->sendFiles(files);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <vector>

 #include <QFileDialog>
 #include <QListWidget>
#include <QMessageBox>

#include <synfilesharing/synfilesharing.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->sendFilesButton->setDisabled(true);

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

    if (ui->selectedFiles->count() <= 0) {
        ui->sendFilesButton->setDisabled(true);
    } else {
        ui->sendFilesButton->setDisabled(false);
    }
}

void MainWindow::deleteClickedItem(QListWidgetItem *item) {
    ui->selectedFiles->takeItem(ui->selectedFiles->row(item));

    if (ui->selectedFiles->count() <= 0) {
        ui->sendFilesButton->setDisabled(true);
    } else {
        ui->sendFilesButton->setDisabled(false);
    }
}

void MainWindow::sendFiles() {
    std::unique_ptr<synfs::IClient> client = synfs::makeClient().build();

    std::vector<std::string> files;
    for (int i = 0; i < ui->selectedFiles->count(); i++) {
        files.push_back(ui->selectedFiles->item(i) ->text().toStdString());
    }

    try {
        client->sendFiles(files);
    } catch (sdbus::Error e) {
        QMessageBox *errMsg = new QMessageBox(
            QMessageBox::Critical,
            "Ошибка!",
            QString::fromStdString(e.getMessage())
        );
        errMsg->setPalette(this->palette());
        errMsg->addButton(QMessageBox::Close);
        errMsg->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "receivedfileswindow.h"
#include "ui_receivedfileswindow.h"

ReceivedFiles::ReceivedFiles(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReceivedFiles)
{
    ui->setupUi(this);
}

ReceivedFiles::~ReceivedFiles()
{
    delete ui;
}

void ReceivedFiles::setFiles(QStringList files) {
    ui->receivedFiles->addItems(files);
}

void ReceivedFiles::on_closeButton_clicked()
{
    this->close();
}


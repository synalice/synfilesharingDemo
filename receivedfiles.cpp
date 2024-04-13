#include "receivedfiles.h"
#include "ui_receivedfiles.h"

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

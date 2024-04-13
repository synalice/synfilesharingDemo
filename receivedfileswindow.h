#ifndef RECEIVEDFILESWINDOW_H
#define RECEIVEDFILESWINDOW_H

#include <QDialog>

namespace Ui {
class ReceivedFiles;
}

class ReceivedFiles : public QDialog
{
    Q_OBJECT

public:
    ReceivedFiles(QWidget *parent = nullptr);
    ~ReceivedFiles();

    void setFiles(QStringList files);

private slots:
    void on_closeButton_clicked();

private:
    Ui::ReceivedFiles *ui;
};

#endif // RECEIVEDFILESWINDOW_H

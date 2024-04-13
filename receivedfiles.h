#ifndef RECEIVEDFILES_H
#define RECEIVEDFILES_H

#include <QDialog>

namespace Ui {
class ReceivedFiles;
}

class ReceivedFiles : public QDialog
{
    Q_OBJECT

public:
    explicit ReceivedFiles(QWidget *parent = nullptr);
    ~ReceivedFiles();

private slots:
    void on_closeButton_clicked();

private:
    Ui::ReceivedFiles *ui;
};

#endif // RECEIVEDFILES_H

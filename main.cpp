#include "mainwindow.h"
#include "receivedfiles.h"

#include <QApplication>

#include <iostream>

#include <synfilesharing/synfilesharing.h>


int main(int argc, char *argv[])
{
    std::vector<std::string> allowedFileExtensions = {".txt", ".md",};
    auto receivedFiles = std::make_shared<std::vector<std::string>>();

    std::unique_ptr<synfs::IServer> server = synfs::makeServer()
        .setAllowedFileExtensions(allowedFileExtensions)
        .setExecFlag(synfs::constants::DEFAULT_EXEC_FLAG)
        .saveResultsTo(receivedFiles)
        .build();

    server->run(argc, argv);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ReceivedFiles r;
    r.show();

    return a.exec();
}

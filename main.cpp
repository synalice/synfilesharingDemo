#include "mainwindow.h"
#include "receivedfileswindow.h"

#include <QApplication>

#include <synfilesharing/synfilesharing.h>

int main(int argc, char *argv[])
{
    std::vector<std::string> allowedFileExtensions = {".txt", ".md",};

    auto receivedFiles = std::make_shared<std::vector<std::string>>();
    bool runViaDBus = false;
    
    try {
        std::unique_ptr<synfs::IServer> server = synfs::makeServer()
            .setAllowedFileExtensions(allowedFileExtensions)
            .saveRunViaDBusTo(runViaDBus)
            .saveResultsTo(receivedFiles)
            .build();
        server->run(argc, argv);
    } catch (sdbus::Error e) {}

    QApplication a(argc, argv);

    MainWindow w;
    ReceivedFiles r;

    if (runViaDBus) {
        QList<QString> files;

        for (const std::string &str : *receivedFiles) {
            files.push_back(QString::fromStdString(str));
        }

        if (!files.empty()) {
            r.setFiles(files);
            r.show();
        } else {
            exit(1);
        }
    } else {
        w.show();
    }

    return a.exec();
}

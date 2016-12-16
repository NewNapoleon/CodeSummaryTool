#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenDirectory_clicked()
{
    QString path = QFileDialog::getExistingDirectory(NULL,tr("open target file directory"),"",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    FileCounter filesat(path);
    filesat.FileSummary();
    QMap<QString,FileInfo> result = filesat.getFileSummary();
    QMap<QString,FileInfo>::iterator resultIt = result.begin();
    while(resultIt!=result.end())
    {
        QString newline = "";
        newline+=resultIt.key();
        newline+=" ";
        newline+=QString::number(resultIt.value().getFileRows());
        ui->CodeSummaryInfo->append(newline);
        resultIt++;
    }

}



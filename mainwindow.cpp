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

    CodeCounterTableModel* myModel = new CodeCounterTableModel(NULL,filesat.getFileSummary());

    ui->codeInfoTable->setModel(myModel);
//    ui->codeInfoTable->show();

    //code structure view
    CodeStructureModel* myFileModel = new CodeStructureModel();

     myFileModel->setRootPath(path);

    ui->codeTreeStructure->setModel(myFileModel);
    ui->codeTreeStructure->setRootIndex(myFileModel->index(path));

//    ui->codeTreeStructure->show();


    // set status of FileCounter and DirCounter
    ui->fileCounter->setText(QString::number(filesat.getFileNumber()));
    ui->subDirCounter->setText(QString::number(filesat.getDirNumber()));
    ui->codeLinesNum->setText(QString::number(filesat.getCodeLinesSum()));
}



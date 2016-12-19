#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    path = "";
    fileTypeFilter.push_back("h");
    fileTypeFilter.push_back("cpp");
    ui->codeSummaryButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenDirectory_clicked()
{
    path = QFileDialog::getExistingDirectory(NULL,tr("open target file directory"),"",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    ui->TargetFileDirectory->setText(path);
    ui->codeSummaryButton->setEnabled(true);
}



void MainWindow::on_codeSummaryButton_clicked()
{
    FileCounter filesat(path,fileTypeFilter);
    filesat.FileSummary();

    CodeCounterTableModel* myModel = new CodeCounterTableModel(NULL,filesat.getFileSummary());

    ui->codeInfoTable->setModel(myModel);

    //code structure view
    CodeStructureModel* myFileModel = new CodeStructureModel();

     myFileModel->setRootPath(path);

     QStringList modelFilters;
     foreach(QString str,fileTypeFilter)
     {
         QString typestr = "*.";
         typestr+=str;
         modelFilters.push_back(typestr);
     }

     myFileModel->setNameFilters(modelFilters);
    ui->codeTreeStructure->setModel(myFileModel);
    ui->codeTreeStructure->setRootIndex(myFileModel->index(path));



    // set status of FileCounter and DirCounter
    ui->fileCounter->setText(QString::number(filesat.getFileNumber()));
    ui->subDirCounter->setText(QString::number(filesat.getDirNumber()));
    ui->codeLinesNum->setText(QString::number(filesat.getCodeLinesSum()));
}



void MainWindow::on_fileFilterButton_clicked()
{
    FileTypeFilterWidget* filterWidget = new FileTypeFilterWidget(NULL,&fileTypeFilter);
    filterWidget->setWindowTitle(tr("目标文件类型"));
    filterWidget->show();
}





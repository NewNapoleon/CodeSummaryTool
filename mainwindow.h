#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filecounter.h"
#include "codecountertablemodel.h"
#include "codestructuremodel.h"
#include "filetypefilterwidget.h"
#include <QFileSystemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_OpenDirectory_clicked();

    void on_codeSummaryButton_clicked();


    void on_fileFilterButton_clicked();

private:
    Ui::MainWindow *ui;
    QString path;
    QStringList fileTypeFilter;

};

#endif // MAINWINDOW_H

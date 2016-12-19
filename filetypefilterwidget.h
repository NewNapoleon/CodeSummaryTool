#ifndef FILETYPEFILTERWIDGET_H
#define FILETYPEFILTERWIDGET_H

#include <QWidget>
#include <QTextDocument>
#include <QTextBlock>

namespace Ui {
class FileTypeFilterWidget;
}

class FileTypeFilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileTypeFilterWidget(QWidget *parent = 0, QStringList *filterTypes=NULL);
    ~FileTypeFilterWidget();

private slots:
    void on_applyFilterButton_clicked();

private:
    Ui::FileTypeFilterWidget *ui;
    QStringList* fileFilterTypes;
};

#endif // FILETYPEFILTERWIDGET_H

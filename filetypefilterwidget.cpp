#include "filetypefilterwidget.h"
#include "ui_filetypefilterwidget.h"

FileTypeFilterWidget::FileTypeFilterWidget(QWidget *parent,QStringList* filterTypes) :
    QWidget(parent),
    ui(new Ui::FileTypeFilterWidget)
{
    ui->setupUi(this);
    // TODO:check null pointer for filterTypes
    fileFilterTypes = filterTypes;
    foreach(QString str,*fileFilterTypes)
    {
        ui->fileFiltersSummary->append(str);
    }
}

FileTypeFilterWidget::~FileTypeFilterWidget()
{
    delete ui;
}

void FileTypeFilterWidget::on_applyFilterButton_clicked()
{
    fileFilterTypes->clear();
    QTextDocument* doc = ui->fileFiltersSummary->document();
    for(int i=0;i<doc->lineCount();i++)
    {
        QTextBlock tb = doc->findBlockByLineNumber(i);
        fileFilterTypes->push_back(tb.text());
    }
}

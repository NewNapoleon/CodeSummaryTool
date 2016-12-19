#include "codecountertableview.h"

CodeCounterTableView::CodeCounterTableView(QWidget *parent):QTableView(parent)
{

}

void CodeCounterTableView::keyPressEvent(QKeyEvent *event)
{
    if(event->matches(QKeySequence::Copy))
    {
        QAbstractItemModel* model = this->model();
        QItemSelectionModel* selection = this->selectionModel();
        QModelIndexList indexes = selection->selectedIndexes();
        qSort(indexes);
        QString selected_file_infos;
        QModelIndex previous = indexes.first();
        indexes.removeFirst();
        foreach(QModelIndex current,indexes)
        {
            QVariant data = model->data(previous);
            QString text = data.toString();
            selected_file_infos.append(text);
            if(current.row()==previous.row())
            {
                selected_file_infos.append('\t');
            }
            else
            {
                selected_file_infos.append('\n');
            }
            previous = current;
        }
        selected_file_infos.append(model->data(indexes.last()).toString());
        QApplication::clipboard()->setText(selected_file_infos);
    }
}

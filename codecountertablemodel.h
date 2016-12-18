#ifndef CODECOUNTERTABLEMODEL_H
#define CODECOUNTERTABLEMODEL_H

#include <QAbstractTableModel>
#include "filecounter.h"
#include <QDebug>


class CodeCounterTableModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    CodeCounterTableModel(QObject* parent,QMap<QString,FileInfo>& fileinfo);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void setCodeFileInfo(QMap<QString,FileInfo>& fileinfo);

    //header
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QList<FileInfo> CodeInfo;

};

#endif // CODECOUNTERTABLEMODEL_H

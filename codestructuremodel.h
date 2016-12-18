#ifndef CODESTRUCTUREMODEL_H
#define CODESTRUCTUREMODEL_H

#include <QFileSystemModel>

class CodeStructureModel:public QFileSystemModel
{
    Q_OBJECT
public:
    CodeStructureModel(QObject* parent=0);
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // CODESTRUCTUREMODEL_H

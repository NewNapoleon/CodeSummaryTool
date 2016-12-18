#include "codestructuremodel.h"

CodeStructureModel::CodeStructureModel(QObject *parent):QFileSystemModel(parent)
{

}

int CodeStructureModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant CodeStructureModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole)
    {
        if(orientation==Qt::Horizontal)
        {
            return tr("文件目录");
        }
    }
    return QVariant();
}

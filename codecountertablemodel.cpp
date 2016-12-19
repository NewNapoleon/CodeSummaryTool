#include "codecountertablemodel.h"

CodeCounterTableModel::CodeCounterTableModel(QObject* parent, QMap<QString, FileInfo> &fileinfo):QAbstractTableModel(parent)
{
    QMap<QString, FileInfo>::iterator fileinfoIt = fileinfo.begin();
    while(fileinfoIt!=fileinfo.end())
    {
        CodeInfo.push_back(fileinfoIt.value());
        fileinfoIt++;
    }
}

int CodeCounterTableModel::rowCount(const QModelIndex &parent) const
{
    // need row counter method
    return CodeInfo.size();
}

int CodeCounterTableModel::columnCount(const QModelIndex &parent) const
{
    //need col counter method
    return 4;
}

QVariant CodeCounterTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
//    qDebug()<<"get data";
    if(role==Qt::DisplayRole)
    {
//        qDebug()<<"get real data";
        switch(col)
        {
        case 0:
            return QVariant(CodeInfo.at(row).getFileName());
            break;
        case 1:
            return QVariant(CodeInfo.at(row).getFileRows());
            break;
        case 2:
            return QVariant(CodeInfo.at(row).getFileType());
            break;
        case 3:
            return QVariant(CodeInfo.at(row).getFileSize());
            break;
        }
    }
    else
    {
//        qDebug()<<"get nothing";
        return QVariant();
    }
}

void CodeCounterTableModel::setCodeFileInfo(QMap<QString, FileInfo> &fileinfo)
{
    CodeInfo.clear();
    QMap<QString, FileInfo>::iterator fileinfoIt = fileinfo.begin();
    while(fileinfoIt!=fileinfo.end())
    {
        CodeInfo.push_back(fileinfoIt.value());
        fileinfoIt++;
    }
}

QVariant CodeCounterTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole)
    {
        if(orientation==Qt::Horizontal)
        {
            switch(section)
            {
            case 0:
               return tr("文件名称");
            case 1:
                return tr("文件行数(LOC)");
            case 2:
                return tr("文件类型");
            case 3:
                return tr("文件大小");
            }
        }
    }
    return QVariant();
}

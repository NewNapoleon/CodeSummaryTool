#include "filecounter.h"
#include <QTextStream>
#include <QDebug>

FileCounter::FileCounter(QString targetpath, QStringList filters):dir(targetpath)
{
    dir.setFilter(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);
    fileinfolist = dir.entryInfoList();
    FileNumber = 0;
    DirNumber = 0;
    codeLinesum = 0;
    fileTypefilters = filters;
}

void FileCounter::setFileFilters(QStringList filters)
{
    dir.setNameFilters(filters);
}

void FileCounter::FileSummary()
{
    if(fileinfolist.empty())
    {
        qDebug()<<"No file";
        return;
    }
    else
    {
        for(int i=0;i<fileinfolist.count();i++)
        {
            QFileInfo fileinfo = fileinfolist.at(i);
            if(fileinfo.isDir())
            {
                QDir tempdir(fileinfo.absoluteFilePath());
                tempdir.setFilter(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);
                DirNumber++;
                FileSummary(tempdir);
            }
            else if(fileTypefilters.contains(fileinfo.suffix()))
            {
                QString FileName = fileinfo.fileName();
                QString FileType = fileinfo.suffix();
                double FileSize = fileinfo.size();
                int FileRows = 0;
                QFile file(fileinfo.absoluteFilePath());
                if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
                {
                    qDebug()<<"open file error: "<<FileName;
                }
                else
                {
                    QTextStream in(&file);
                    while(!in.atEnd())
                    {
                        QString line = in.readLine();
                        FileRows++;
                    }
                }
                codeLinesum+=FileRows;
                FileInfo info(FileName,FileType,FileRows,FileSize);
                FileNumber++;
                filesummary.insert(FileName,info);
            }
        }
    }
}

void FileCounter::FileSummary(QDir dir)
{
    QFileInfoList dirfiles = dir.entryInfoList();
    if(dirfiles.empty())
    {
        return;
    }
    else
    {
        for(int i=0;i<dirfiles.size();i++)
        {
           QFileInfo tempfile = dirfiles.at(i);
           if(tempfile.isDir())
           {
               QDir tempdir(tempfile.absoluteFilePath());
               tempdir.setFilter(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);
               DirNumber++;
               FileSummary(tempdir);
           }
           else if(fileTypefilters.contains(tempfile.suffix()))
           {
               QString FileName = tempfile.fileName();
               QString FileType = tempfile.suffix();
               double FileSize = tempfile.size();
               int FileRows = 0;
               QFile file(tempfile.absoluteFilePath());
               if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
               {
                   qDebug()<<"open file error: "<<FileName;
               }
               else
               {
                   QTextStream in(&file);
                   while(!in.atEnd())
                   {
                       QString line = in.readLine();
                       FileRows++;
                   }
               }
               codeLinesum+=FileRows;
               FileInfo info(FileName,FileType,FileRows,FileSize);
               FileNumber++;
               filesummary.insert(FileName,info);
           }
        }
    }
}

QMap<QString,FileInfo> FileCounter::getFileSummary()
{
    return filesummary;
}

#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include <QDir>
#include <QFileInfo>
#include <QMap>


class FileInfo{
public:
    FileInfo(QString FileName,QString FileType,int FileRows,double FileSize):fileName(FileName),fileType(FileType),fileRows(FileRows),fileSize(FileSize)
    {
        //init File Summary info
    }

    int getFileRows()
    {
        return fileRows;
    }

private:
    QString fileName;
    QString fileType;
    int fileRows;
    double fileSize;

};

class FileCounter
{
public:
    FileCounter(QString targetpath);
    void setFileFilters(QStringList filters);
    QMap<QString,FileInfo> getFileSummary();
     void FileSummary();//interface for customer use
     int getFileNumber()//get how many files
     {
         return FileNumber;
     }

     int getDirNumber()//get how many dirs
     {
         return DirNumber;
     }
     int getCodeLinesSum()
     {
         return codeLinesum;
     }

private:
    QDir dir;
    QFileInfoList fileinfolist;
    QMap<QString,FileInfo> filesummary;
    void FileSummary(QDir dir);//real logic
    int FileNumber;
    int DirNumber;
    int codeLinesum;
};

#endif // FILECOUNTER_H

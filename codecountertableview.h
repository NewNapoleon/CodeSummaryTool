#ifndef CODECOUNTERTABLEVIEW_H
#define CODECOUNTERTABLEVIEW_H

#include <QTableView>
#include <QKeyEvent>
#include <QApplication>
#include <QClipboard>

class CodeCounterTableView:public QTableView
{
    Q_OBJECT
public:
    CodeCounterTableView(QWidget* parent=0);

protected:
    void keyPressEvent(QKeyEvent * event);

signals:

public slots:
};

#endif // CODECOUNTERTABLEVIEW_H

#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T23:59:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = codesummary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filecounter.cpp \
    codecountertablemodel.cpp \
    codestructuremodel.cpp

HEADERS  += mainwindow.h \
    filecounter.h \
    codecountertablemodel.h \
    codestructuremodel.h

FORMS    += mainwindow.ui

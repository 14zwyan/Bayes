#-------------------------------------------------
#
# Project created by QtCreator 2017-03-31T22:29:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bayes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bayes.cpp \
    data.cpp \
    reader.cpp \
    testdata.cpp \
    txtreader.cpp

HEADERS  += mainwindow.h \
    bayes.h \
    data.h \
    reader.h \
    testdata.h \
    txtreader.h

FORMS    += mainwindow.ui

DISTFILES += \
    Bayes.pro.user

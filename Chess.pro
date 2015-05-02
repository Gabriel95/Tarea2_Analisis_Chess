#-------------------------------------------------
#
# Project created by QtCreator 2012-03-21T22:01:54
#
#-------------------------------------------------

QT       += core gui
QT += gui declarative
TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tile.cpp \
    piece.cpp

HEADERS  += mainwindow.h \
    tile.h \
    piece.h

FORMS    += mainwindow.ui

RESOURCES += \
    Images.qrc

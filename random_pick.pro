#-------------------------------------------------
#
# Project created by QtCreator 2022-04-28T13:35:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = random_pick
TEMPLATE = app


SOURCES += main.cpp\
        lotterydraw.cpp \
    mythread.cpp

HEADERS  += lotterydraw.h \
    mythread.h

FORMS    += lotterydraw.ui

RESOURCES += \
    res.qrc

RC_ICONS = ./favicon.ico

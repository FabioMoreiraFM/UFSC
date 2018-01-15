#-------------------------------------------------
#
# Project created by QtCreator 2016-08-05T15:13:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoPiloto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    imagem.cpp \
    web.cpp \
    regperso.cpp \
    data.cpp \
    personagem.cpp

HEADERS  += mainwindow.h \
    login.h \
    imagem.h \
    web.h \
    regperso.h \
    data.h \
    personagem.h

FORMS    += mainwindow.ui \
    login.ui \
    imagem.ui \
    web.ui \
    regperso.ui \
    data.ui

RESOURCES += \
    resource.qrc

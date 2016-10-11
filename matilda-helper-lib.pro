#-------------------------------------------------
#
# Project created by QtCreator 2016-10-11T11:22:04
#
#-------------------------------------------------

QT       -= gui

TARGET = matilda-helper-lib
TEMPLATE = lib
VERSION = 1.0.0

DEFINES += MATILDAHELPERLIB_LIBRARY

SOURCES += matildahelperlib.cpp

HEADERS += matildahelperlib.h \
    matilda-helper-def.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

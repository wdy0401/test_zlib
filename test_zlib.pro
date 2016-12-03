QT += core
QT -= gui

CONFIG += c++11

TARGET = test_zlib
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    zlib128-dll/include/zconf.h \
    zlib128-dll/include/zlib.h

win32: LIBS += -L$$PWD/zlib128-dll/lib/ -lzdll

INCLUDEPATH += $$PWD/zlib128-dll/include
DEPENDPATH += $$PWD/zlib128-dll/include

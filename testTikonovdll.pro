QT += core
QT -= gui

CONFIG += c++11

TARGET = testTikonovdll
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \






HEADERS += \
    E:/john/matlabcoder/codegen/dll/landwebercode/landwebercode.h \
    Tikhonov/Tikhonov.h


    E:/john/matlabcoder/codegen/dll/Tikhonov/Tikhonov.h

LIBS += ./landwebercode/landwebercode.lib \
       ./Tikhonov/Tikhonov.lib

#win32: LIBS += -L$$PWD/E:/john/matlabcoder/codegen/dll/landwebercode/ -l landwebercode

#INCLUDEPATH += $$PWD/E:/john/matlabcoder/codegen/dll/landwebercode
#DEPENDPATH += $$PWD/E:/john/matlabcoder/codegen/dll/landwebercode

#win32: LIBS += -L$$PWD/E:/john/matlabcoder/codegen/dll/Tikhonov/ -l Tikhonov

#INCLUDEPATH += $$PWD/E:/john/matlabcoder/codegen/dll/Tikhonov
#DEPENDPATH += $$PWD/E:/john/matlabcoder/codegen/dll/Tikhonov

DISTFILES += \
    b.txt \
    L.txt \
    Tikhonov/Tikhonov.lib \
    Tikhonov/Tikhonov.dll


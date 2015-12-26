#-------------------------------------------------
#
# Project created by QtCreator 2015-07-03T12:36:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Student_Management
TEMPLATE = app


SOURCES += main.cpp\
        root.cpp \
    newstudent.cpp \
    studentinformation.cpp \
    personinfo.cpp \
    terminfo.cpp \
    studentinfo.cpp \
    datamanager.cpp

HEADERS  += root.h \
    newstudent.h \
    studentinformation.h \
    personinfo.h \
    terminfo.h \
    studentinfo.h \
    datamanager.h

FORMS    += root.ui \
    newstudent.ui \
    studentinformation.ui

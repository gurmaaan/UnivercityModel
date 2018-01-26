TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    department.cpp \
    faculty.cpp \
    laboratory.cpp \
    student.cpp \
    employee.cpp \
    men.cpp

HEADERS += \
    department.h \
    faculty.h \
    laboratory.h \
    student.h \
    employee.h \
    men.h

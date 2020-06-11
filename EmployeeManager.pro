TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Employee.cpp \
        Helpper.cpp \
        main.cpp

HEADERS += \
    Employee.h \
    Helpper.h

DISTFILES += \
    ImportData.csv

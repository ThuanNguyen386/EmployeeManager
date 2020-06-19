TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Employee.cpp \
        Helpper.cpp \
        RollCallHistory.cpp \
        StatusDate.cpp \
        main.cpp

DISTFILES += \
    ImportData.csv \
    projectManagerEmployee.pro.user

HEADERS += \
    Employee.h \
    Helpper.h \
    RollCallHistory.h \
    StatusDate.h

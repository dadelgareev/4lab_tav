QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    taskwindow.cpp \
    taskwindow2.cpp \
    taskwindow3.cpp \
    taskwindow6.cpp

HEADERS += \
    mainwindow.h \
    taskwindow.h \
    taskwindow2.h \
    taskwindow3.h \
    taskwindow6.h

FORMS += \
    mainwindow.ui \
    taskwindow.ui \
    taskwindow2.ui \
    taskwindow3.ui \
    taskwindow6.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT       += core gui sql
#RC_ICONS = myappico.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcaldialog.cpp \
    addcashdialog.cpp \
    addnotedialog.cpp \
    main.cpp \
    mainwindow.cpp \
    reminder.cpp \
    seecaldialog.cpp \
    seecashdialog.cpp \
    seenotedialog.cpp

HEADERS += \
    addcaldialog.h \
    addcashdialog.h \
    addnotedialog.h \
    mainwindow.h \
    reminder.h \
    seecaldialog.h \
    seecashdialog.h \
    seenotedialog.h

QMAKE_CXXFLAGS += -std=gnu++14
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    addcaldialog.ui \
    addcashdialog.ui \
    addnotedialog.ui \
    reminder.ui \
    seecaldialog.ui \
    seecashdialog.ui \
    seenotedialog.ui

#RESOURCES += \
#    res.qrc

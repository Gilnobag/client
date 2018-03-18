#-------------------------------------------------
#
# Project created by QtCreator 2018-03-07T02:18:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/include/


SOURCES += \
    source/main.cpp \
    source/gui/uniticon.cpp \
    source/gui/gui.cpp \
    source/gui/recruitmentscene.cpp \
    source/units/unit.cpp \
    source/gui/mainmenu.cpp \
    source/gui/guiscenemanager.cpp \
    source/gui/detatchedwidget.cpp \
    source/gui/playervsplayerintro.cpp \
    source/race.cpp \
    source/racemanager.cpp \
    source/units/mage.cpp \
    source/units/warrior.cpp \
    source/gui/scene.cpp \
    source/gui/raceicon.cpp \
    source/playermanager.cpp

HEADERS += \
    include/gui/uniticon.h \
    include/gui/gui.h \
    include/gui/recruitmentscene.h \
    include/units/unit.h \
    include/abstractfactory.h \
    include/player.h \
    include/gui/mainmenu.h \
    include/gui/guiscenemanager.h \
    include/gui/detatchedwidget.h \
    include/gui/playervsplayerintro.h \
    include/race.h \
    include/racemanager.h \
    include/units/mage.h \
    include/units/warrior.h \
    include/gui/scene.h \
    include/gui/raceicon.h \
    include/playermanager.h

FORMS += \
    include/gui/gui.ui \
    include/gui/recruitmentscene.ui \
    include/gui/mainmenu.ui \
    include/gui/playervsplayerintro.ui

RESOURCES += \
    gui.qrc

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    PlaneAbstract.cpp \
    PlaneCommercial.cpp \
    ControlTower.cpp \
    PlaneProducer.cpp \
    PlaneContainer.cpp

HEADERS += \
    PlaneAbstract.h \
    utils.h \
    PlaneCommercial.h \
    ControlTower.h \
    PlaneProducer.h \
    PlaneContainer.h

LIBS += -pthread

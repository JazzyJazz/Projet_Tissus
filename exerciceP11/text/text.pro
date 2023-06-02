QMAKE_CXXFLAGS += -std=c++11

CONFIG += console

TARGET = exerciceP11

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    text_viewer.cc

HEADERS += \
    ../general/systeme.h \
    text_viewer.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h \
    ../general/masse.h \
    ../general/tissuS.h \
    ../general/vecteur3D.h
    

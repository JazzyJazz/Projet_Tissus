TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11

SOURCES = \
    vecteur3D.cpp \
    masse.cpp \
    ressort.cpp \
    integrateur.cpp \
    tissuS.cpp \
    tissusGeo.cpp \
    contraintes.cpp \
    systeme.cpp 


HEADERS += \
    vecteur3D.h \
    dessinable.h \
    support_a_dessin.h \
    masse.h \
    ressort.h \
    integrateur.h \
    tissuS.h \
    tissusGeo.h \
    contraintes.h \
    systeme.h 

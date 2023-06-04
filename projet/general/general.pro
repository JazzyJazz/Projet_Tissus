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
    dessinable.h \
    support_a_dessin.h \
    vecteur3D.h \
    masse.h \
    ressort.h \
    integrateur.h \
    tissuS.h \
    tissusGeo.h \
    contraintes.h \
    systeme.h 

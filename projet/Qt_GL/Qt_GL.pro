QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = sim_tissu

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h \
    ../general/vecteur3D.h \
    ../general/masse.h \
    ../general/tissuS.h \
    ../general/tissusGeo.h \
    ../general/contraintes.h \
    ../general/systeme.h \
    

RESOURCES += \
    resource.qrc

CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
# CXXFLAGS += -g                  # pour debugger
# CXXFLAGS += -O2                 # pour optimiser la vitesse

all: testV

testV: testVecteur3D.o vecteur3D.o
	$(CXX) -o testV testVecteur3D.o vecteur3D.o

testVecteur3D.o: testVecteur3D.cpp vecteur3D.h

vecteur3D.o: vecteur3D.cpp vecteur3D.h


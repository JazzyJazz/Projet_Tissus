CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
# CXXFLAGS += -g                  # pour debugger
# CXXFLAGS += -O2                 # pour optimiser la vitesse

all: testTissuS

#testV
testV: testVecteur3D.o vecteur3D.o
	$(CXX) -o testV testVecteur3D.o vecteur3D.o

testVecteur3D.o: testVecteur3D.cpp vecteur3D.h

vecteur3D.o: vecteur3D.cpp vecteur3D.h

#testM
testM: testMasse.o vecteur3D.o masse.o ressort.o
	$(CXX) -o testM testMasse.o vecteur3D.o masse.o ressort.o

testMasse.o: testMasse.cpp vecteur3D.h masse.h ressort.h

masse.o: masse.cpp vecteur3D.h masse.h ressort.h

#testR
testR: testRessort.o vecteur3D.o masse.o ressort.o
	$(CXX) -o testR testRessort.o vecteur3D.o masse.o ressort.o

testRessort.o: testRessort.cpp vecteur3D.h masse.h ressort.h

ressort.o: ressort.cpp vecteur3D.h masse.h ressort.h

#testI
testI: testIntegrateur3.o vecteur3D.o masse.o ressort.o integrateur.o
	$(CXX) -o testI testIntegrateur3.o vecteur3D.o masse.o ressort.o integrateur.o

testIntegrateur3.o: testIntegrateur3.cpp vecteur3D.h masse.h ressort.h integrateur.h

integrateur.o: integrateur.cpp vecteur3D.h masse.h ressort.h integrateur.h

#testTissu
testTissuS: testTissuS.o vecteur3D.o masse.o ressort.o integrateur.o tissuS.o
	$(CXX) -o testTissuS testTissuS.o vecteur3D.o masse.o ressort.o integrateur.o tissuS.o

testTissuS.o: testTissuS.cpp vecteur3D.h masse.h ressort.h tissuS.h

tissuS.o: tissuS.cpp vecteur3D.h masse.h ressort.h integrateur.h tissuS.h
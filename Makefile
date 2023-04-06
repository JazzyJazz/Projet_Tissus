CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
# CXXFLAGS += -g                  # pour debugger
# CXXFLAGS += -O2                 # pour optimiser la vitesse

all: testM 

#testV
testV: testVecteur3D.o vecteur3D.o
	$(CXX) -o testV testVecteur3D.o vecteur3D.o

testVecteur3D.o: testVecteur3D.cpp vecteur3D.h

vecteur3D.o: vecteur3D.cpp vecteur3D.h

#testM
testM: testMasse.o masse.o vecteur3D.o ressort.o
	$(CXX) -o testM testMasse.o masse.o vecteur3D.o ressort.o

testMasse.o: testMasse.cpp masse.h vecteur3D.h ressort.h

masse.o: masse.cpp vecteur3D.h ressort.h

#testR
testR: testRessort.o masse.o vecteur3D.o ressort.o
	$(CXX) -o testM testMasse.o masse.o vecteur3D.o ressort.o

testRessort.o: testRessort.cpp ressort.h masse.h vecteur3D.h

ressort.o: ressort.cpp masse.h vecteur3D.h

#testI
testInt: testIntegrateur1.o masse.o
	$(CXX) -o testInt testIntegrateur1.o masse.o

testIntegrateur1.o: testIntegrateur1.cpp testIntegrateur1.h vecteur3D.h
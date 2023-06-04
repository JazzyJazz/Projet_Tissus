#include <iostream>
#include <vector>

#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"

using namespace std;

// Accsesseurs
Masse* Ressort::get_masse_a() const{return masse_a;}
Masse* Ressort::get_masse_d() const{return masse_d;}
double Ressort::get_k() const{return k;}
double Ressort::get_l0() const{return l0;}

// Constructeur
Ressort::Ressort(Masse* D, Masse* A, double raideur, double longueur0):masse_d(D), masse_a(A), k(raideur), l0(longueur0){
	// Ajout du ressort dans la liste des ressorts des 2 masses
	D->add_ressort(this);
	A->add_ressort(this);
}

// Méthodes
Vecteur3D Ressort::force_rappel(Masse* const& m){
	double distance;
	double norme_force;
	distance = (((*masse_d).get_position() - (*masse_a).get_position()).norme());
	norme_force = k*(distance - l0);

	// Si la masse n'est pas celle de départ ou celle d'arrivée, il n'y a pas de force subie
	if ((*masse_a != *m) and (*masse_d != *m)){
		return Vecteur3D();
	}
	// Force subie par la masse d'arrivée = - Force subie par la masse de départ
	else if ((*masse_a) == *m){
		return norme_force*(~((*masse_d).get_position() - (*masse_a).get_position()));
	}
	else{
		return norme_force*(~((*masse_a).get_position() - (*masse_d).get_position()));
	}
}

// Surcharge 
ostream& operator<<(ostream& s, Ressort const& r){
	s << "Ressort " << &r << " :" << endl;
	s << " - Constante de raideur : " << r.get_k() << endl;
	s << " - Longueur au repos : " << r.get_l0() << endl;
	s << "# Masse depart : " << *(r.get_masse_d()) << endl;
	s << "# Masse arrivée : " << *(r.get_masse_a()) << endl;
	return s;
}

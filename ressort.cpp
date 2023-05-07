#include <iostream>
#include <vector>
#include <cmath>

#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"

using namespace std;

//accsesseurs
Masse* Ressort::get_masse_a() const{return masse_a;}
Masse* Ressort::get_masse_d() const{return masse_d;}
double Ressort::get_k() const{return k;}
double Ressort::get_l0() const{return l0;}

//constructeur
Ressort::Ressort(Masse* D, Masse* A, double raideur, double longueur0):masse_d(D), masse_a(A), k(raideur), l0(longueur0){
	D->add_ressort(this);
	A->add_ressort(this);
}

//méthode
Vecteur3D Ressort::force_rappel(Masse* const& m){
	double distance;
	double norme_force;
	distance = (((*masse_d).get_position() - (*masse_a).get_position()).norme());
	norme_force = k*(distance - l0);
	if ((*masse_a != *m) and (*masse_d != *m)){
		return Vecteur3D();
	}
	else if ((*masse_a) == *m){
		return norme_force*(~((*masse_d).get_position() - (*masse_a).get_position()));
	}
	else{
		return norme_force*(~((*masse_a).get_position() - (*masse_d).get_position()));
	}
}


//surcharge de l'opérateur affiche
ostream& operator<<(ostream& s, Ressort const& r){
	s << "Ressort " << &r << " :" << endl;
	s << r.get_k() << " # cst raideur" << endl;
	s << r.get_l0() << " # longueur au repos" << endl;
	s << "# masse depart : Masse " << r.get_masse_d() << ":" << endl;
	s << *(r.get_masse_d());
	s << "# masse arrivée : Masse " << r.get_masse_a() << ":" << endl;
	s << *(r.get_masse_a());
	return s;
}

#include <iostream>
#include <vector>
#include <cmath>
#include "vecteur3D.h"
#include "masse.h"
using namespace std;

Vecteur3D Ressort::force_rappel(){
	return Vecteur3D();
}

// Accesseurs
Vecteur3D Masse::get_position() const {return position;}
Vecteur3D Masse::get_vitesse() const {return vitesse;}
double Masse::get_masse() const {return masse;}
double Masse::get_coeff() const {return coeff;}
Vecteur3D Masse::get_force_subie() const {return force_subie;}

void Masse::set_position(Vecteur3D pos_){position = pos_;}
void Masse::set_vitesse(Vecteur3D vit_){vitesse = vit_;}
void Masse::set_masse(double m_){
	if (m_ > 0){masse = m_;}
}


// Constructeur
Masse::Masse(Vecteur3D pos, Vecteur3D vit, double m, double coeffi, Vecteur3D fs, vector<Ressort>& ressorts):position(pos), vitesse(vit), masse(m), coeff(coeffi), force_subie({0,0,9.81*m}), liste_ressort(ressorts){}


// Méthodes
void Masse::ajoute_force(Vecteur3D const& df){
	force_subie += df;
}

Vecteur3D Masse::acceleration(){
	return{force_subie*(1/masse)};
}

void Masse::mise_a_jour_forces(){
	Vecteur3D v = Vecteur3D();
	for (auto& elem : liste_ressort) {
		v += elem.force_rappel();
	}
	force_subie = (v+Vecteur3D(0,0,-9.81*masse)-(coeff*vitesse));
}
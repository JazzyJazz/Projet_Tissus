#include <iostream>
#include <vector>
#include <cmath>
#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"
using namespace std;

// Accesseurs
Vecteur3D Masse::get_position() const {return position;}
Vecteur3D Masse::get_vitesse() const {return vitesse;}
double Masse::get_masse() const {return masse;}
double Masse::get_coeff() const {return coeff;}
Vecteur3D Masse::get_force_subie() const {return force_subie;}
vector<Ressort> Masse::get_ressorts() const {return liste_ressort;}

void Masse::set_position(Vecteur3D pos_){position = pos_;}
void Masse::set_vitesse(Vecteur3D vit_){vitesse = vit_;}
void Masse::set_masse(double m_){
	if (m_ > 0){masse = m_;}
}

//Bonjour
// Constructeur
Masse::Masse(Vecteur3D pos, Vecteur3D vit, double m, double coeffi, vector<Ressort>& ressorts):position(pos), vitesse(vit), masse(m), coeff(coeffi), force_subie({0,0,-9.81*m}), liste_ressort(ressorts){}


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
		v += elem.force_rappel(*this);
	}
	force_subie = (v+Vecteur3D(0,0,-9.81*masse)-(coeff*vitesse));
}

ostream& operator<<(ostream& s, Masse const& m){
	s << "Masse : " << m.get_masse() << endl;
	s << "Position : " << m.get_position() << endl;
	s << "Vitesse : " << m.get_vitesse() << endl;
	s << "Coefficient : " << m.get_coeff() << endl;
	s << "Résultante des forces" << m.get_force_subie() << endl;
	s << "Ressorts : " << (m.get_ressorts()).size() << endl;
	return s;
}

#include <iostream>
#include <vector>
#include <cmath>

#include "vecteur3D.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"

using namespace std;

// Accesseurs
Vecteur3D Masse::get_position() const {return position;}
Vecteur3D Masse::get_vitesse() const {return vitesse;}
double Masse::get_masse() const {return masse;}
double Masse::get_coeff() const {return coeff;}
Vecteur3D Masse::get_force_subie() const {return force_subie;}
vector<Ressort*> const& Masse::get_ressorts() const {return liste_ressort;}

// Manimulateurs 
void Masse::set_position(Vecteur3D pos_){position = pos_;}
void Masse::set_vitesse(Vecteur3D vit_){vitesse = vit_;}
void Masse::set_masse(double m_){
	if (m_ > 0){masse = m_;}
}
void Masse::set_coeff(double c_){
	if (c_ > 0){coeff = c_;}
}
bool Masse::color_vit() const {return col;}
void Masse::set_color_vit(bool b){col = b;}

void Masse::add_ressort(Ressort* const& ressort){liste_ressort.push_back(ressort);}


// Constructeur
Masse::Masse(double m, Vecteur3D pos, Vecteur3D vit, double coeffi, bool col_):position(pos), vitesse(vit), masse(abs(m)), coeff(coeffi), force_subie({0,0,-9.81*m}), col(col_){}

// Méthodes
void Masse::ajoute_force(Vecteur3D const& df){
	force_add = df;
}

Vecteur3D Masse::acceleration(){
	return{force_subie*(1/masse)};
}

void Masse::mise_a_jour_forces(){
	Vecteur3D v = Vecteur3D();
	for (auto& elem : liste_ressort) {
		v += elem->force_rappel(this);
	}
	force_subie = v + Vecteur3D(0,0,-9.81*masse)-(coeff*vitesse) + force_add;
	force_add = Vecteur3D();
}

void Masse::statique(){
	vitesse = Vecteur3D();
	
	Vecteur3D v = Vecteur3D();
	for (auto& elem : liste_ressort) {
		v += elem->force_rappel(this);
	}
	
	ajoute_force(Vecteur3D(0,0,9.81*masse) - v);
}

void Masse::dessine_sur(SupportADessin& support){
	support.dessine(*this);
}

// Surcharges 
bool Masse::operator==(Masse const& m1){
	if(masse == m1.get_masse() and position == m1.get_position() and vitesse == m1.get_vitesse() and coeff == m1.get_coeff() and force_subie == m1.get_force_subie() and liste_ressort == m1.get_ressorts()){
		return true;
	}
	return false;
};

bool Masse::operator!=(Masse const& m1){
	return not(*this == m1);
}

ostream& operator<<(ostream& s, Masse const& m){
	s << "Masse " << &m << " : " << endl;
	s << "- Masse : " << m.get_masse() << endl;
	s << "- Coefficient : " << m.get_coeff() << endl;
	s << "- Position : " << m.get_position() << endl;
	s << "- Vitesse : " << m.get_vitesse() << endl;
	s << "- Résultante des forces" << m.get_force_subie() << endl;
	s << "- Ressorts : " << (m.get_ressorts()).size() << endl;
	for (auto& elem : m.get_ressorts()) {
		s << elem << endl;
	}
	return s;
}



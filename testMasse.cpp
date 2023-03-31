#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur3D.h"
#include "Vecteur3D.cpp"
using namespace std;

class Masse{
private:
Vecteur3D position;
Vecteur3D vitesse;
double masse;
const double coeff;
Vecteur3D force_subie;
std::vector<Ressort> liste_ressort;

public:
Vecteur3D get_position() const {return position};
Vecteur3D get_vitesse() const {return vitesse};
double get_masse() const {return masse};
double get_coeff() const {return coeff};
Vecteur3D get_force_subie const {return force_subie};

void set_position(pos_){position = pos_};
void set_vitesse(vit_){vitesse = vit_};
void set_masse(m_){
	if (m_ > 0){
		{masse = m_};
	}
}
//modifier les autres valeurs n'a pas de sens

Masse(Vecteur3D pos, Vecteur3D vit, double m, double coeffi, Vecteur3D fs, std::vector<Ressort>& ressorts)
:position(pos), vitesse(vit), masse(m), coeff(coeffi), force_subie((0,0,9.81*m)), liste_ressort(ressorts){}

void ajoute_force(Vecteur3D const& df)
{
	return{force_subie + df};
}

Vecteur3D acceleration()
{
	return{force_subie*(1/masse)};
}

void mise_a_jour_forces()
{
	Vecteur3D v();
	for (const auto& elem : liste_ressort) {
        v += force_rappel();
    }
    force_subie = (v+(-9.81*Vecteur3D(0,0,m))-(coeff*vitesse) );
}

};

int main()
{
return 0;
}

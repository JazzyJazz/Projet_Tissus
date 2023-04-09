#pragma once
#ifndef MASSE_H
#define MASSE_H
#include "vecteur3D.h"


#include <vector>

class Ressort;

class Masse{
	private:
		Vecteur3D position;
		Vecteur3D vitesse;
		double masse;
		const double coeff;
		Vecteur3D force_subie;
		std::vector<Ressort*> liste_ressort;

	public:
		// Accesseurs
		Vecteur3D get_position() const;
		Vecteur3D get_vitesse() const;
		double get_masse() const;
		double get_coeff() const;
		Vecteur3D get_force_subie() const;
		std::vector<Ressort*> get_ressorts() const;

		void set_position(Vecteur3D);
		void set_vitesse(Vecteur3D);
		void set_masse(double);
		void add_ressort(Ressort* const&);
		// modifier les autres valeurs n'a pas de sens

		// Constructeurs
		Masse(double, Vecteur3D = Vecteur3D(), Vecteur3D = Vecteur3D(), double = 0, std::vector<Ressort*> const& = std::vector<Ressort*>());

		// Méthodes
		void ajoute_force(Vecteur3D const&);

		Vecteur3D acceleration();

		void mise_a_jour_forces();

		//Opérateurs logiques
		bool operator==(Masse const&);

		bool operator!=(Masse const&);
};

std::ostream& operator<<(std::ostream& s, Masse const& m);

#endif
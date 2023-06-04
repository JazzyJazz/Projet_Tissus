#pragma once

#ifndef MASSE_H
#define MASSE_H

#include <iostream>
#include <vector>

#include "vecteur3D.h"
#include "dessinable.h"

// "Forward declaration" de Ressort pour pouvoir l'utiliser dans Masse
class Ressort;

class Masse : public Dessinable{
	private:
		Vecteur3D position;
		Vecteur3D vitesse;
		double masse;
		double coeff;
		Vecteur3D force_subie;
		Vecteur3D force_add;
		std::vector<Ressort*> liste_ressort;
		bool col;

	public:
		// Accesseurs
		Vecteur3D get_position() const;
		Vecteur3D get_vitesse() const;
		double get_masse() const;
		double get_coeff() const;
		Vecteur3D get_force_subie() const;
		std::vector<Ressort*> const& get_ressorts() const;
		bool color_vit() const;

		// Manipulateurs
		void set_position(Vecteur3D pos_);
		void set_vitesse(Vecteur3D vit_);
		void set_masse(double m_);
		void set_coeff(double c_);
		void set_color_vit(bool b);
		void add_ressort(Ressort* const& res);
		// (modifier les autres valeurs n'a pas de sens)

		// Constructeurs
		Masse(double m_, Vecteur3D pos = Vecteur3D(), Vecteur3D vit = Vecteur3D(), double coeff = 0, bool col_ = true);
		Masse(Masse&) = delete;
		virtual ~Masse() = default;

		// Méthodes
		void ajoute_force(Vecteur3D const& force);

		Vecteur3D acceleration();

		void mise_a_jour_forces();

		void statique();

		//Opérateurs logiques
		bool operator==(Masse const& m1);

		bool operator!=(Masse const& m1);

		virtual void dessine_sur(SupportADessin& support) override;
};

std::ostream& operator<<(std::ostream& s, Masse const& m1);

#endif
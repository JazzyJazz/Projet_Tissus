#pragma once

#ifndef RESSORT_H
#define RESSORT_H

#include <iostream>

#include "vecteur3D.h"
#include "masse.h"

class Ressort{
	private:
		// Attributs 
		Masse* masse_d;
		Masse* masse_a;
		const double k;
		const double l0;

	public:
		// Accesseurs
		Masse* get_masse_d() const;
		Masse* get_masse_a() const;
		double get_k() const;
		double get_l0() const;
		
		// Constructeurs
		Ressort(Masse* m_d, Masse* m_a, double k_, double l0_);
		Ressort(Ressort&) = delete;
		~Ressort() = default;
		
		// Méthode
		Vecteur3D force_rappel(Masse* const&);
		
};

// Opérateur d'affichage
std::ostream& operator<<(std::ostream&, Ressort const&);

#endif
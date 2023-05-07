#pragma once

#ifndef RESSORT_H
#define RESSORT_H

#include "vecteur3D.h"
#include "masse.h"


class Ressort{
	private:
		//attributs 
		Masse* masse_d;
		Masse* masse_a;
		const double k;
		const double l0;

	public:
		//accsesseurs
		Masse* get_masse_d() const;
		Masse* get_masse_a() const;
		double get_k() const;
		double get_l0() const;
		
		//constructeur
		Ressort(Masse*, Masse*, double, double);
		
		//méthode
		Vecteur3D force_rappel(Masse* const&);
		
};

//opérateur d'affichage
std::ostream& operator<<(std::ostream&, Ressort const&);

#endif
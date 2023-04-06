#pragma once
#include "vecteur3D.h"
#include "masse.h"

class Ressort{
	private:
		//attributs 
		Masse masse_d;
		Masse masse_a;
		const double k;
		const double l0;
	public:
		//accsesseurs
		Masse get_masse_d() const;
		Masse get_mase_a() const;
		double get_k() const;
		double get_l0() const;
		
		void set_masse_d(Masse);
		void set_masse_a(Masse);
		
		//constructeur
		Ressort(Masse, Masse , double, double);
		
		//méthode
		Vecteur3D force_rappel(Masse const&);
	
		//opérateur
		Ressort& operator <<() const;
		
};

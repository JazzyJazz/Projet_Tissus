#include <iostream>
#include <vector>
#include <cmath>
#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"
using namespace std;

//accsesseurs
Masse Ressort::get_mase_a() const{return masse_a;}
Masse Ressort::get_masse_d() const{return masse_d;}
double Ressort::get_k() const{return k;}
double Ressort::get_l0() const{return l0;}

void Ressort::set_masse_d(Masse d){masse_d = d;}
void Ressort::set_masse_a(Masse a){masse_a = a;}

//constructeur
Masse::Masse(Masse D, Masse A, double raideur, double longueur0):masse_d(D), masse_a(A), k(raideur), l0(longueur0){}

//méthode
Vecteur3D::force_rappel(Masse m){
	double distance;
	double norme_force;
	distance = (norme(masse_d.position - masse_a.position));
	norme_force = k*(distance - l0);
	if ((m != masse_a) and (m != masse_d)){
		return 0;
	}else if (m == masse_a){
		
	}else{
		
	}
}

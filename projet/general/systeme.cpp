#include <iostream>
#include <vector>
#include <cmath>

#include "dessinable.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"
#include "tissuS.h"
#include "systeme.h"
#include "contraintes.h"

using namespace std;

// Constructeur
Systeme::Systeme(vector<TissuS*> tissus_):tissus(tissus_){}

void Systeme::dessine_sur(SupportADessin& support){
    support.dessine(*this);
}

std::vector<TissuS*> Systeme::get_tissus() const{
    return tissus;
}

void Systeme::add_tissu(TissuS* tissu){
    tissus.push_back(tissu);
}

// Surcharge
ostream& operator<<(std::ostream& s, Systeme const& sys){
    string str_tissus(" tissus");
    if(sys.get_tissus().size() == 0){return s << "Le système est vide" << endl;}
    else if(sys.get_tissus().size() == 1){str_tissus = " tissu";}

    s << "Le système est composé de " << sys.get_tissus().size() << str_tissus << " : " << endl;

    for(size_t i(0); i < sys.get_tissus().size(); i++){
        string str_masses(" masses");
        if(sys.get_tissus().size() == 1){str_masses = " masse";}
        string str_ressorts(" ressorts");
        if(sys.get_tissus().size() == 1){str_ressorts = " ressort";}

        cout << endl << "Le tissu " << i+1 << " est constitué de " << sys.get_tissus()[i]->get_masses().size() << str_masses << " et " << sys.get_tissus()[i]->get_ressorts().size() << str_ressorts << " : " << endl << endl; 
        for(Masse* m : sys.get_tissus()[i]->get_masses()){
            cout << *m << endl;
        }
        for(Ressort* r : sys.get_tissus()[i]->get_ressorts()){
            cout << *r << endl;
        }
    }

    return s;
}

// Méthodes
void Systeme::evolue(double dt){
    temps += dt;
    for(TissuS* t : tissus){
        for(Contrainte* c : contraintes){
            c->appliquer(t, temps);
        }
        t->evolve(dt);
    }
}

void Systeme::affiche_masses(ostream& flot) const{
    for(TissuS* t : tissus){
        flot << " --- TISSU " << t << " --- " << endl << endl;
        for(Masse* m : t->get_masses()){
            flot << *m << endl;
        }
    }
}

void Systeme::add_contrainte(Contrainte* c){
    contraintes.push_back(c);
}

double Systeme::get_energy() const{
    double E;
    for(TissuS* t : tissus){
        for(Masse* m : t->get_masses()){
            E += (m->get_vitesse())*(m->get_vitesse())*m->get_masse()/2;
            E += m->get_masse() * m->get_position().get_vect()[2] * 9.81;
        }
        for(Ressort* res : t->get_ressorts()){
            E += pow((res->get_masse_d()->get_position() - res->get_masse_a()->get_position()).norme() - res->get_l0(), 2)*res->get_k()/2;
        }
    }
    return E;
}

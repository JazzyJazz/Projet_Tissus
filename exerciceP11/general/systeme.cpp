#include <iostream>
#include <vector>

#include "dessinable.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"
#include "tissuS.h"
#include "systeme.h"

using namespace std;

Systeme::Systeme(vector<TissuS*> tissus_):tissus(tissus_),angle(0.0){}

void Systeme::dessine_sur(SupportADessin& support){
    support.dessine(*this);
}

std::vector<TissuS*> Systeme::get_tissus() const{
    return tissus;
}

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

void Systeme::evolue(double dt){
    for(TissuS* t : tissus){
        t->evolve(dt);
    }
    constexpr double omega(100.0);
    angle += omega * dt;
}

void Systeme::affiche_masses() const{
    for(TissuS* t : tissus){
        cout << " --- TISSU " << t << " --- " << endl << endl;
        for(Masse* m : t->get_masses()){
            cout << *m << endl;
        }
    }
}

double Systeme::get_angle() const{return angle;}
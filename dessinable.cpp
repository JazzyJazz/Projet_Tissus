#include <iostream>

#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"
#include "tissuS.h"
#include "dessinable.h"

using namespace std;

Systeme::Systeme(vector<TissuS*> tissus_):tissus(tissus_){}

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

    for(size_t i; i < sys.get_tissus().size(); i++){
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
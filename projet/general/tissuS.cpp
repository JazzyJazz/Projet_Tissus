#include <vector>
#include <algorithm>

#include "dessinable.h"
#include "vecteur3D.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"
#include "integrateur.h"
#include "tissuS.h"


using namespace std;

// Constructeur
Ressort_Temp::Ressort_Temp(Masse* m1, Masse* m2, double r, double l0):m_d(m1),m_a(m2),r(r),l0(l0){}


// Méthodes 
bool TissuS::check(){
    for(Ressort* res : ressorts){
        if((*res).get_masse_d() == (*res).get_masse_a()){
            return false;
        }
        else if((*res).get_masse_d() == nullptr or (*res).get_masse_a() == nullptr){
            return false;
        }
        bool t1(false);
        for(Ressort* res2 : res->get_masse_d()->get_ressorts()){
            if(res == res2){
                t1 = true;
            }
        }
        if(not t1){return false;}
    }
    for(Masse* masse : masses){
        if((masse->get_ressorts()).size() == 0){
            return false;
        }
        
        for(Ressort* res : masse->get_ressorts()){
            if(masse != res->get_masse_d() and masse != res->get_masse_a()){
                return false;
            }
        }
    }
    return true;
}

TissuS::TissuS(vector<Masse*> ms):masses(ms){i = 1;}

TissuS::TissuS(TissuS& tissu){
    for(Masse* m: tissu.get_masses()){
        masses.push_back(new Masse(m->get_masse(), m->get_position(), m->get_vitesse(), m->get_coeff()));
    }
    for(Ressort* r : tissu.get_ressorts()){
        int i = (find(tissu.get_masses().begin(), tissu.get_masses().end(), r->get_masse_d())-tissu.get_masses().begin());
        int j = (find(tissu.get_masses().begin(), tissu.get_masses().end(), r->get_masse_a())-tissu.get_masses().begin());
        ressorts.push_back(new Ressort(masses[i], masses[j], r->get_k(), r->get_l0()));
    }
    i = tissu.get_integrateur();
}

void TissuS::connecte(unsigned int n1, unsigned int n2, double raideur, double l0){
    if(n1 > masses.size()-1 or n2 > masses.size()-1){
        return;
    }
    ressorts_temp.push_back(Ressort_Temp(masses[n1], masses[n2], raideur, l0));
}

void TissuS::connecte_masses(){
    for(Ressort_Temp r_temp : ressorts_temp){
        Ressort* r1 = new Ressort(r_temp.m_d, r_temp.m_a, r_temp.r, r_temp.l0);
        ressorts.push_back(r1);
    }
}

void TissuS::maj_forces(){
    for(Masse* masse : masses){
        masse->mise_a_jour_forces();
    }
}

void TissuS::evolve(double dt){
    maj_forces();
    for(Masse* masse : masses){
        switch(i){
            case 2:{
                IntegrateurNewmark inte2; 
                inte2.evolve(*masse, dt); 
                break;
            }
            case 3:{
                IntegrateurRungeKutta inte3; 
                inte3.evolve(*masse, dt); 
                break;
            }
            default:{
                IntegrateurEulerCromer inte;
                inte.evolve(*masse, dt); 
                break;
            }
        }
    }
}

void TissuS::set_integrateur(int i_){
    i = i_;
}

vector<Masse*> TissuS::get_masses() const{
    return masses;
}

vector<Ressort*> TissuS::get_ressorts() const{
    return ressorts;
}

int TissuS::get_integrateur() const{
    return i;
}

void TissuS::set_color_vit(bool b){
    for(Masse* m : masses){
        m->set_color_vit(b);
    }
}

void TissuS::dessine_sur(SupportADessin& support){
    support.dessine(*this);
}

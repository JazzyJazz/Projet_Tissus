#include "tissuS.h"
#include "masse.h"
#include "vecteur3D.h"
#include "ressort.h"
#include "integrateur.h"
#include <vector>
#include <iostream>

using namespace std;

Ressort_Temp::Ressort_Temp(Masse* m1, Masse* m2, double r, double l0):m_d(m1),m_a(m2),r(r),l0(l0){}


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

TissuS::TissuS(vector<Masse*> ms):masses(ms){}

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
    cout << check();
}

void TissuS::maj_forces(){
    for(Masse* masse : masses){
        masse->mise_a_jour_forces();
    }
}

void TissuS::evolve(double dt){
    IntegrateurEulerCromer i;
    for(Masse* masse : masses){
        i.evolve(*masse, dt);
    }
}
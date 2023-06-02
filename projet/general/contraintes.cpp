#include <vector>
#include <cmath>

#include "dessinable.h"
#include "vecteur3D.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"
#include "tissuS.h"
#include "contraintes.h"

using namespace std;

Contrainte::Contrainte(Vecteur3D pos_, double ray_):pos(pos_),ray(ray_){}

bool Contrainte::isIn(Masse* m_){
    return ((m_->get_position()-pos).norme() <= ray);
}

Crochet::Crochet(Vecteur3D pos_, double ray_):Contrainte(pos_, ray_){}

void Crochet::appliquer(TissuS* tissu, double temps_){
    for(Masse* m : tissu->get_masses()){
        if(isIn(m)){m->statique();}
    }
}

Impulsion::Impulsion(Vecteur3D pos_, double ray_, double t_deb, double t_fin, Vecteur3D force_, vector<TissuS*> tissus_):Contrainte(pos_, ray_),t_i(t_deb),t_f(t_fin),force(force_){
    for(TissuS* t : tissus_){
        for(Masse* m : t->get_masses()){
            if(isIn(m)){masses.push_back(m);}
        }
    }
}

void Impulsion::appliquer(TissuS* tissu, double temps_){
    if(temps_ >= t_i and temps_ <= t_f){
        for(Masse* m : masses){
            m->ajoute_force(force + Vecteur3D(0, 0, m->get_masse()*9.81));
        }
    }
}

ImpulsionSin::ImpulsionSin(Vecteur3D pos_, double ray_, double t_deb, double t_fin, Vecteur3D force_i, vector<TissuS*> tissus_, double freq_):Impulsion(pos_, ray_, t_deb, t_fin, force_i, tissus_),freq(freq_),f_i(force_i){}

void ImpulsionSin::appliquer(TissuS* tissu, double temps_){
    force = f_i * sin(2*M_PI*freq*(temps_ - t_i));
    Impulsion::appliquer(tissu, temps_);
}
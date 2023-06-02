#include <vector>
#include <cmath>

#include "dessinable.h"
#include "vecteur3D.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"
#include "integrateur.h"
#include "tissuS.h"
#include "tissusGeo.h"

using namespace std;

TissuChaine::TissuChaine(double m_, double coeff_, double k_, double l0_, vector<Vecteur3D> positions_):TissuS(){
    for(Vecteur3D pos : positions_){
        Masse* m = new Masse(m_, pos, Vecteur3D(), coeff_);
        masses.push_back(m);
    }

    for(size_t i(0); i < masses.size() - 1; i++){
        connecte(i, i+1, k_, l0_);
    }

    connecte_masses();
}

TissuRectangle::TissuRectangle(double m_, Vecteur3D long_, Vecteur3D larg_, Vecteur3D pos0, double coeff_, double dens_lin_, double k_, double l0_):TissuS(){
    if(((larg_ ^ long_) != Vecteur3D())){
        larg_ -= ((larg_ * long_)*long_ * (1.0/long_.norme2()));

        int nb_long = floor(long_.norme() / dens_lin_)+1;
        int nb_larg = floor(larg_.norme() / dens_lin_)+1;

        Vecteur3D long_unit = (~long_);
        Vecteur3D larg_unit = (~larg_);

        for(int i(0); i < nb_long; i++){
            for(int j(0); j < nb_larg; j++){
                Vecteur3D pos = pos0 + long_unit*dens_lin_*i + larg_unit*dens_lin_*j;
                Masse* m = new Masse(m_, pos, Vecteur3D(), coeff_);
                masses.push_back(m);
            }
        }

        for(int i(0); i < nb_larg*nb_long; i++){
            if(i < (nb_long-1)*nb_larg){
                connecte(i, i+nb_larg, k_, l0_);
            }
            if((i+1)%nb_larg != 0){
                connecte(i, i+1, k_, l0_);
            }
        }

        connecte_masses();
    }
}

TissuDisque::TissuDisque(double m_, Vecteur3D pos0, Vecteur3D ray_, double pas_rad,  double coeff_, double k_, double pas_ang):TissuS(){
    Vecteur3D u = Vecteur3D(0, -ray_.get_vect()[2], ray_.get_vect()[1]);
    if(ray_.get_vect()[1] == 0 and ray_.get_vect()[2] == 0){
        u = Vecteur3D(0, 1, 0);
    }

    int nb_ray = ray_.norme() / pas_rad;
    int nb_ang = 360 / pas_ang;
    pas_ang *= M_PI/180;


    Masse* m = new Masse(m_, pos0, Vecteur3D(), coeff_);
    masses.push_back(m);
    for(size_t i(0); i < nb_ang; i++){
        for(size_t j(1); j < nb_ray+1; j++){
            Vecteur3D pos = pos0 + (~u)*j;
            Masse* m = new Masse(m_, pos, Vecteur3D(), coeff_);
            masses.push_back(m);
        }
        u = (cos(pas_ang)*(~u) + sin(pas_ang)*(~(ray_ ^ u)));
    }

    for(int i(1); i < nb_ray*nb_ang+1; i++){
        double l0 = (masses[i]->get_position() - masses[((i+nb_ray-1)%(nb_ray*nb_ang)+1)]->get_position()).norme();
        connecte(i, ((i+nb_ray-1)%(nb_ray*nb_ang)+1), k_, l0);
        if((i-1)%nb_ray == 0){
            double l0 = (masses[i]->get_position() - pos0).norme();
            connecte(0, i, k_, l0);
        }
        else{
            double l0 = (masses[i]->get_position() - masses[i-1]->get_position()).norme();
            connecte(i-1, i, k_, l0);
        }
        
    }

    connecte_masses();

}

TissuCompose::TissuCompose(vector<TissuS*> tissus, double k_, double eps_):TissuS(),k(k_),eps(eps_){
    // On suppose qu'il n'y a pas de masses en double (dans les 2 tissus en même temps)
    for(TissuS* t : tissus){
        for(Masse* m : t->get_masses()){
            masses.push_back(m);
        }

        for(Ressort* r : t->get_ressorts()){
            ressorts.push_back(r);
        }
    }
}

void TissuCompose::raccommode(){
    for(int i(0); i < masses.size(); i++){
        for(int j(0); j < masses.size(); j++){
            Masse* m1 = masses[i]; 
            Masse* m2 = masses[j];
            if(m1 != m2){
                if((m1->get_position()-m2->get_position()).norme() < eps){
                    bool linked(false);
                    for(Ressort* r1 : m1->get_ressorts()){
                        if(linked){break;}
                        for(Ressort* r2 : m2->get_ressorts()){
                            if(r1 == r2){
                                linked = true;
                                break;
                            }
                        }
                    }
                    if(not linked){
                        if((m1->get_position() - m2->get_position()).norme() < 1e-5){
                            m2->set_position(m2->get_position() + Vecteur3D(1e-4, 1e-4, 1e-4));
                        }
                        Ressort* r1 = new Ressort(m1, m2, k, (m1->get_position() - m2->get_position()).norme());
                        ressorts.push_back(r1);
                    }
                }
            }
        }
    }
}
#include "vecteur3D.h"
#include "masse.h"
#include "integrateur.h"

using namespace std;

// Constructeur de Newmark (avec le epsilon)
IntegrateurNewmark::IntegrateurNewmark(double eps_):eps(eps_){}

// Méthode evolve() des intégrateurs 
void IntegrateurEulerCromer::evolve(Masse& m, double dt) const{
    // Application du résumé mathématique
    Vecteur3D pos = m.get_position();
    Vecteur3D vit = m.get_vitesse();
    m.set_vitesse(vit += m.acceleration()*dt);
    m.set_position(pos += vit*dt);
}

void IntegrateurNewmark::evolve(Masse& m, double dt) const{
    // Application du résumé mathématique 
    Vecteur3D pos = m.get_position();
    Vecteur3D vit = m.get_vitesse();
    Vecteur3D q = pos;
    Vecteur3D s = m.acceleration();
    do{
        q = m.get_position();
        Vecteur3D r = m.acceleration(); // acceleration() est indépendante du temps !
        m.set_vitesse(vit + dt/2 * (r+s));
        m.set_position(pos + dt * vit + dt*dt/3*(r/2 + s));
    }while((q-m.get_position()).norme() > eps);
}

void IntegrateurRungeKutta::evolve(Masse& m, double dt) const{
    // Application du résumé mathématique
    Vecteur3D pos = m.get_position();
    Vecteur3D vit = m.get_vitesse();
    Vecteur3D k1 = vit;
    //
    Vecteur3D k1_ = m.acceleration();
    Vecteur3D k2 = vit + k1_*(dt/2);
    //
    m.set_position(pos + k1*(dt/2));
    m.set_vitesse(vit + k1_*(dt/2));
    Vecteur3D k2_ = m.acceleration();   // acceleration() est indépendante du temps !
    Vecteur3D k3 = vit + k2_*(dt/2);
    //
    m.set_position(pos + k2*(dt/2));
    m.set_vitesse(vit + k2_*(dt/2));
    Vecteur3D k3_ = m.acceleration();   // acceleration() est indépendante du temps !
    Vecteur3D k4 = vit + k3_*dt;
    //
    m.set_position(pos + k3*dt);
    m.set_vitesse(vit + k3_*dt);
    Vecteur3D k4_ = m.acceleration();   // acceleration() est indépendante du temps !
    //
    m.set_position(pos + (k1+2*k2+2*k3+k4)*(dt/6));
    m.set_vitesse(vit + (k1_+2*k2_+2*k3_+k4_)*(dt/6));
}

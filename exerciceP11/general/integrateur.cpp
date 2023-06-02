#include "vecteur3D.h"
#include "masse.h"
#include "integrateur.h"

using namespace std;

void IntegrateurEulerCromer::evolve(Masse& m, double dt) const{
    Vecteur3D pos = m.get_position();
    Vecteur3D vit = m.get_vitesse();
    m.set_vitesse(vit += m.acceleration()*dt);
    m.set_position(pos += vit*dt);
}

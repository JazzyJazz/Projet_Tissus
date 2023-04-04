#include "integrateur.h"
#include "masse.h"
#include <vector>

using namespace std;

int main(){
    IntegrateurEulerCromer i;
    vector<Ressort> v;
    Masse m(Vecteur3D(0, 0, 0), Vecteur3D(1, 0, 2), 0.127, 0.0, Vecteur3D(), v);

    double dt = 0.01;
    i.evolve(m, dt);
}
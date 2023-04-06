#include "integrateur.h"
#include "masse.h"
#include "vecteur3D.h"
#include "ressort.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    IntegrateurEulerCromer i;
    vector<Ressort> v;
    Masse m(Vecteur3D(), Vecteur3D(1, 0, 2), 0.127, 0.0, v);

    double dt = 0.01;
    while(m.get_position().get_vect()[2] >= 0){
        i.evolve(m, dt);
        cout << m << endl;
    }
}
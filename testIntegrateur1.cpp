#include "integrateur.h"
#include "masse.h"
#include "vecteur3D.h"
#include "ressort.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    IntegrateurEulerCromer i;
    Masse m(0.127, Vecteur3D(0, 0, 1), Vecteur3D(1, 0, 2));

    double dt = 0.01;
    double t = 0;
    while(m.get_position().get_vect()[2] >= 0){
        cout << "==================" << endl << "t = " << t << endl << m << endl;
        t += dt;
        i.evolve(m, dt);
    }
}
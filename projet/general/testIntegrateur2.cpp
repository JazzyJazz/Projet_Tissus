#include <iostream>
#include <vector>

#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"
#include "integrateur.h"

using namespace std;

// TEST

int main(){
    IntegrateurEulerCromer i;
    Masse* m1 = new Masse(1, Vecteur3D(), Vecteur3D(), 0.3);
    Masse* m2 = new Masse(1, Vecteur3D(2, 0, 0), Vecteur3D(), 0.3);
    Masse* m3 = new Masse(1, Vecteur3D(0, 2, 0), Vecteur3D(), 0.3);

    Ressort* r1 = new Ressort(m1, m2, 9, 1.5);
    Ressort* r2 = new Ressort(m1, m3, 1.9, 1.75);
    Ressort* r3 = new Ressort(m2, m3, 5.5, 1.25);

    double dt = 0.1;
    double t = 0;
    while(t < 0.3){
        cout << "==================" << endl << "t = " << t << endl << *m1 << endl << *m2 << endl;
        t += dt;
        m1->ajoute_force(Vecteur3D(0, 0, 9.81));
        m2->ajoute_force(Vecteur3D(0, 0, 9.81));
        m3->ajoute_force(Vecteur3D(0, 0, 9.81));
        m1->mise_a_jour_forces();
        m2->mise_a_jour_forces();
        m3->mise_a_jour_forces();
        i.evolve(*m1, dt);
        i.evolve(*m2, dt);
        i.evolve(*m3, dt);
    }
}
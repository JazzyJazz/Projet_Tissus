#include <iostream>
#include <vector>

#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"
#include "integrateur.h"

using namespace std;

int main(){
    IntegrateurEulerCromer i;
    Masse* m1 = new Masse(0.33, Vecteur3D(0, 0, -3), Vecteur3D(), 0.3);
    Masse* m2 = new Masse(1, Vecteur3D(-0.5, 0, 0), Vecteur3D(), 0.3);
    Masse* m3 = new Masse(1, Vecteur3D(0.5, 0, 0), Vecteur3D(), 0.3);

    Ressort* r1 = new Ressort(m1, m2, 0.6, 2.5);
    Ressort* r2 = new Ressort(m1, m3, 0.6, 2.5);

    double dt = 0.1;
    double t = 0;
    while(t < 5){
        cout << "==================" << endl << "t = " << t << endl << *m1 << endl << endl;
        t += dt;
        m2->ajoute_force(Vecteur3D(0, 0, 9.81) - r1->force_rappel(m2));
        m3->ajoute_force(Vecteur3D(0, 0, 9.81) - r2->force_rappel(m3));
        m1->mise_a_jour_forces();
        m2->mise_a_jour_forces();
        m3->mise_a_jour_forces();
        i.evolve(*m1, dt);
        i.evolve(*m2, dt);
        i.evolve(*m3, dt);
    }
}
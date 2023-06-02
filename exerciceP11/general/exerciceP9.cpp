#include <iostream>
#include <vector>

#include "vecteur3D.h"
#include "masse.h"
#include "tissuS.h"
#include "systeme.h"

using namespace std;

// EXERCICE

int main(){
    Masse* m1 = new Masse(0.33, Vecteur3D(0, 0, -3), Vecteur3D(), 0.3);
    Masse* m2 = new Masse(1, Vecteur3D(-0.5, 0, 0), Vecteur3D(), 0.3);
    Masse* m3 = new Masse(1, Vecteur3D(0.5, 0, 0), Vecteur3D(), 0.3);

    vector<Masse*> masses{m1, m2, m3};

    TissuS* tissu = new TissuS(masses);
    //Ressort* r1 = new Ressort(m1, m2, 0.6, 2.5);
    tissu->connecte(0, 1, 0.6, 2.5);
    //Ressort* r2 = new Ressort(m1, m3, 0.6, 2.5);
    tissu->connecte(0, 2, 0.6, 2.5);
    tissu->connecte_masses();

    vector<TissuS*> tissus{tissu};

    Systeme sys = Systeme(tissus);

    cout << sys;

    return 0;
}
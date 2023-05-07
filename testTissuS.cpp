#include <iostream>
#include <vector>

#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"
#include "tissuS.h"

using namespace std;

int main(){
    vector<Masse*> masses;
    masses.push_back(new Masse(1));
    masses.push_back(new Masse(1, Vecteur3D(1, 1, 1)));
    masses.push_back(new Masse(1, Vecteur3D(-1, -1, -1), Vecteur3D(-1, 1, -1), 0.1));
    TissuS tissu = TissuS(masses);

    tissu.connecte(0, 2, 10.1, 1);
    tissu.connecte(1, 2, 2.5, 0);
    tissu.connecte(2, 0, 1.25, 0.5);
    tissu.connecte_masses();
    tissu.evolve(0.1);
    return 0;
}
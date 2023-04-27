#include "tissuS.h"
#include "masse.h"
#include "vecteur3D.h"
#include "ressort.h"
#include <vector>
#include <iostream>

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
    return 0;
}
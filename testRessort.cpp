#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){    
    Masse* m1 = new Masse(15, Vecteur3D(1, 2, 3), Vecteur3D(4, 5, 6), 0.5);
    Masse* m2 = new Masse(5);
    Ressort* r1 = new Ressort(m1, m2, 2.0, 1.0);
    m1->add_ressort(r1);
    m2->add_ressort(r1);
    cout << *r1 << endl;
    return 0;
}
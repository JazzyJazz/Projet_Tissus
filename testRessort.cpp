#include <iostream>
#include <vector>

#include "vecteur3D.h"
#include "masse.h"
#include "ressort.h"

using namespace std;

int main(){
    Masse* m1 = new Masse(1);
    Masse* m2 = new Masse(2);
    Masse* m3 = new Masse(10, Vecteur3D(1, 0, 2), Vecteur3D(0, 1, 0), 0.1);

    // Ressort 1
    Ressort* r1 = new Ressort(m1, m2, 3, 1);
    
    // Ressort 2
    Ressort* r2 = new Ressort(m2, m3, 1, 0);

    m2->set_position(Vecteur3D(42, 42, 42));
    m2->ajoute_force(Vecteur3D(42, 42, 42));
    m2->set_vitesse(Vecteur3D(42, 42, 42));
    m2->set_coeff(0.3);

    cout << *r1 << endl << endl;

    cout << "Force ressort " << r1 << " sur masse " << m1 << " : " << r1->force_rappel(m1) << endl;
    cout << "Force ressort " << r1 << " sur masse " << m2 << " : " << r1->force_rappel(m2) << endl;
    cout << "Force ressort " << r1 << " sur masse " << m3 << " : " << r1->force_rappel(m3) << endl;
    return 0;
}
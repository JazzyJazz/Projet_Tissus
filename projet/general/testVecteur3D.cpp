#include <iostream>

#include "vecteur3D.h"

using namespace std;

int main(){
    Vecteur3D vect1;
    Vecteur3D vect2;
    Vecteur3D vect3;

    // v1 = (1.0, 2.0, -0.1)
    vect1.set_coord(0, 1.0);
    vect1.set_coord(1, 2.0);
    vect1.set_coord(2, -0.1);

    // v2 = (2.6, 3.5,  4.1)
    vect2.set_coord(0, 2.6);
    vect2.set_coord(1, 3.5);
    vect2.set_coord(2, 4.1); 

    vect3 = vect1;

    cout << vect1 << " + " << vect2 << " = " << endl;

    vect2 += vect1;

    cout << vect2 << endl;

    return 0;
}
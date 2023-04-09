#include "masse.h"
#include "vecteur3D.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){    
    Masse m1 = Masse(15, Vecteur3D(1, 2, 3), Vecteur3D(4, 5, 6), 0.5);
    Masse m2 = Masse(5);
    cout << m1 << endl << m2 << endl;
    return 0;
}
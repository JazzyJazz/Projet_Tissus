#include "masse.h"
#include "vecteur3D.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    Vecteur3D pos = Vecteur3D();
    Vecteur3D vit = Vecteur3D(1, 0, 0);
    vector<Ressort> res;
    
    Masse m(pos, vit, 20, 0, res);
    cout << m << endl;
    return 0;
}
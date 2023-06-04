#include <iostream>
#include "text_viewer.h"
#include "vecteur3D.h"
#include "systeme.h"
#include "masse.h"
#include "tissuS.h"
using namespace std;

int main(){
  Systeme sys;

  //A REMPLIR
  TextViewer ecran(cout /* A MODIFIER */);

  ecran.evolue(sys);
  return 0;
}

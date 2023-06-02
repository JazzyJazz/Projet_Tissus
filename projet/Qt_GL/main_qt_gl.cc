#include <QApplication>
#include <vector> 
#include <cmath>

#include "glwidget.h"
#include "vecteur3D.h"
#include "masse.h"
#include "tissuS.h"
#include "tissusGeo.h"
#include "contraintes.h"
#include "systeme.h"

using namespace std;

int main(int argc, char* argv[]){
  QApplication a(argc, argv);
  //Systeme à remplir
  Systeme sys;
  

  // Fenêtre affichée
  GLWidget w;
  w.set_sys(sys);
  w.show();

  return a.exec();
}
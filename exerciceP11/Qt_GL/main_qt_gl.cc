#include <QApplication>
#include <vector> 

#include "glwidget.h"
#include "vecteur3D.h"
#include "masse.h"
#include "tissuS.h"
#include "systeme.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  Masse* m1 = new Masse(0.33, Vecteur3D(0, 0, 0), Vecteur3D(), 0.3);
  Masse* m2 = new Masse(1, Vecteur3D(-0.5, 0, 0), Vecteur3D(), 0.3);
  Masse* m3 = new Masse(1, Vecteur3D(0.5, 0, 0), Vecteur3D(), 0.3);

  std::vector<Masse*> masses{m1, m2, m3};

  TissuS* tissu = new TissuS(masses);
  //Ressort* r1 = new Ressort(m1, m2, 0.6, 2.5);
  tissu->connecte(0, 1, 0.6, 2.5);
  //Ressort* r2 = new Ressort(m1, m3, 0.6, 2.5);
  tissu->connecte(0, 2, 0.6, 2.5);
  tissu->connecte_masses();

  std::vector<TissuS*> tissus{tissu};

  Systeme sys = Systeme(tissus);

  GLWidget w;

  w.set_sys(&sys);
  
  w.show();

  return a.exec();
}

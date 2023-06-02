#include <iostream> // pour endl
#include "text_viewer.h"
#include "systeme.h"
#include "masse.h"
#include "tissuS.h"

using namespace std;

void TextViewer::dessine(Systeme const& a_dessiner){
  a_dessiner.affiche_masses(flot);
}

void TextViewer::dessine(Masse const& a_dessiner){
  flot << a_dessiner << endl;
}

void TextViewer::dessine(TissuS const& a_dessiner){
  for(Masse* m : a_dessiner.get_masses()){
    flot << *m << endl;
  } 
}


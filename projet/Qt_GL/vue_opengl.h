#pragma once

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>

#include "support_a_dessin.h"
#include "vecteur3D.h"
#include "masse.h"
#include "tissuS.h"
#include "systeme.h"

class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Masse const& a_dessiner) override;
  virtual void dessine(TissuS const& a_dessiner) override;
  virtual void dessine(Systeme const& a_dessiner) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes de transformation de matrice
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // Méthodes utilitaires offertes pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4(), Vecteur3D col = Vecteur3D(0, 0, 1));
  void dessineLigne(Vecteur3D pos1, Vecteur3D pos2, QMatrix4x4 const& point_de_vue = QMatrix4x4());

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;

  // Caméra
  QMatrix4x4 matrice_vue;
};

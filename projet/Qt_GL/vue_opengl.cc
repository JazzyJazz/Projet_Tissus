#include <vector>
#include <cmath>

#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "vecteur3D.h"
#include "masse.h"
#include "tissuS.h"
#include "systeme.h"

// ======================================================================
void VueOpenGL::dessine(Masse const& a_dessiner){
  // Dessin d'une masse
  QMatrix4x4 matrice;
  // Recupération des positions / vitesses
  Vecteur3D pos = a_dessiner.get_position();
  Vecteur3D vit = a_dessiner.get_vitesse();

  // Choix de la couleur : entre bleu et rouge si "couleur = vitesse" est activé, bleu sinon
  Vecteur3D col = Vecteur3D(0, 0, 1);
  if(a_dessiner.color_vit()){
    /* Pour éviter qu'on aie des valeurs au dessus de 1 ou en dessous de 0, 
    comme la norme est toujours >= 0, on utilise la fonction tanh(x) : [0, ...[ -> [0, 1[ */
    col = Vecteur3D(tanh(vit.norme()/5), 0, 1-tanh(vit.norme()/5));
  }
  
  /* Translation de la masse vers sa position, 
  en agrandissant celle-ci par la racine cubique de sa masse (effet plus réaliste)*/
  matrice.translate(pos.get_vect()[0], pos.get_vect()[1], pos.get_vect()[2]);
  matrice.scale(0.2 * cbrt(a_dessiner.get_masse()));

  // Dessin final de la masse
  dessineCube(matrice, col);
}

void VueOpenGL::dessine(TissuS const& a_dessiner){
  // Dessin d'un tissu = dessin de toutes ses masses + dessin de tous ses ressorts
  for(Masse* m : a_dessiner.get_masses()){
    m->dessine_sur(*this);
  }
  // Ressort = ligne verte entre les masses
  for(Ressort* res : a_dessiner.get_ressorts()){
    Vecteur3D pos1 = res->get_masse_d()->get_position();
    Vecteur3D pos2 = res->get_masse_a()->get_position();
    dessineLigne(pos1, pos2);
  }
}

void VueOpenGL::dessine(Systeme const& a_dessiner){
  // Dessiner un système = dessiner tous ses tissus
  for(TissuS* tissus : a_dessiner.get_tissus()){
    tissus->dessine_sur(*this);
  }
}

// ======================================================================
void VueOpenGL::init(){
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition(){
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
  matrice_vue.rotate(-60.0, 1.0, 0.0, 0.0);
  matrice_vue.rotate(-30.0, 0.0, 0.0, 1.0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z){
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z){
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue, Vecteur3D col){
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, col.get_vect()[0], 0.0, col.get_vect()[2]); 

  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}

void VueOpenGL::dessineLigne(Vecteur3D pos1, Vecteur3D pos2, QMatrix4x4 const& point_de_vue){
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);
  
  prog.setAttributeValue(SommetId, pos1.get_vect()[0], pos1.get_vect()[1], pos1.get_vect()[2]);
  prog.setAttributeValue(SommetId, pos2.get_vect()[0], pos2.get_vect()[1], pos2.get_vect()[2]);

  glEnd();
}

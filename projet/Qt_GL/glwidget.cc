#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include <iostream>
#include <fstream>

#include "glwidget.h"
#include "systeme.h"

// ======================================================================
void GLWidget::initializeGL(){
  vue.init();
  timerId = startTimer(20);
}

// ======================================================================
void GLWidget::resizeGL(int width, int height){
  /* On commance par dire sur quelle partie de la 
   * fenêtre OpenGL doit dessiner.
   * Ici on lui demande de dessiner sur toute la fenêtre. */

  glViewport(0, 0, width, height);

  /* Puis on modifie la matrice de projection du shader.
   * Pour ce faire on crée une matrice identité (constructeur 
   * par défaut), on la multiplie par la droite par une matrice
   * de perspective. */

  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidget::paintGL(){
  /* On modifie la fenêtre pour : 
    - La réinitialiser, effacer l'ancien dessin du système
    - Redessiner le nouveau système sur celle-ci
  */ 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  sys->dessine_sur(vue);
}

// ======================================================================
void GLWidget::keyPressEvent(QKeyEvent* event){
  constexpr double petit_angle(5.0); // en degrés
  constexpr double petit_pas(1.0);

  // Pour chaque touche, on attribue une action qui va changer soit le point de vue, soit l'angle de vue.
  switch (event->key()) {

  case Qt::Key_Left:
    vue.rotate(petit_angle, 0.0, -1.0, 0.0);
    break;

  case Qt::Key_Right:
    vue.rotate(petit_angle, 0.0, +1.0, 0.0);
    break;

  case Qt::Key_Up:
    vue.rotate(petit_angle, -1.0, 0.0, 0.0);
    break;

  case Qt::Key_Down:
    vue.rotate(petit_angle, +1.0, 0.0, 0.0);
    break;

  case Qt::Key_PageUp:
  case Qt::Key_W:
    vue.translate(0.0, 0.0,  petit_pas);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_S:
    vue.translate(0.0, 0.0, -petit_pas);
    break;

  case Qt::Key_A:
    vue.translate( petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_D:
    vue.translate(-petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_R:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_F:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_Q:
    vue.rotate(petit_angle, 0.0, 0.0, -1.0);
    break;

  case Qt::Key_E:
    vue.rotate(petit_angle, 0.0, 0.0, +1.0);
    break;

  case Qt::Key_Home:
    vue.initializePosition();
    break;

  case Qt::Key_Space:
	  pause();
	  break;
  };

  update(); // redessine
}

// ======================================================================
void GLWidget::timerEvent(QTimerEvent* event){
  Q_UNUSED(event);

  /* Pour chaque pas de temps, on : 
  - Met à jour le temps total
  - On fait évoluer le système
  - On écrit la nouvelle valeur de l'énergie dans le fichier
  - On met à jour la fenêtre */

  double dt = chronometre.restart() / 1000.0;
  t += dt;
  sys->evolue(dt);
  draw_energy();
  update();
}

// ======================================================================
void GLWidget::pause(){
  if(timerId == 0){
	  // dans ce cas le timer ne tourne pas alors on le lance
	  timerId = startTimer(20);
	  chronometre.restart();
  } 
  else {
	  // le timer tourne alors on l'arrête
	  killTimer(timerId);
	  timerId = 0;
  }
}

// ======================================================================
void GLWidget::draw_energy(){
  /* Le tableau est composé de 2 valeurs conséqutives : le temps, puis l'énergie du système à ce temps
  Ensuite, on écrit simplement ces valeurs dans le fichier "energy.txt", de manière à pouvoir l'afficher avec gnuplot
  */ 
  tab_energy.push_back(t);
  tab_energy.push_back(sys->get_energy());
  std::ofstream file;
  file.open("energy.txt");

  for(size_t i(0); i < (tab_energy.size()/2); i++){
    file << tab_energy[2*i] << ", " << tab_energy[2*i+1] << std::endl;
  }
}

// ======================================================================
void GLWidget::set_sys(const Systeme& sys_){
  // On met le système choisi comme système à dessiner.
  sys = &sys_;
}
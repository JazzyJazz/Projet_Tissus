#pragma once

#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps

#include "vue_opengl.h"
#include "systeme.h"

class GLWidget : public QOpenGLWidget{
  public:
    // Constructeurs et Destructeurs
    GLWidget(QWidget* parent = nullptr):QOpenGLWidget(parent){}
    virtual ~GLWidget() = default;
    // Accesseurs et modifieurs
    void set_sys(Systeme& sys_);

  private:
    // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
    virtual void initializeGL() override;
    virtual void resizeGL(int width, int height) override;
    virtual void paintGL() override;
  
    // Méthodes de gestion d'évènements
    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void timerEvent(QTimerEvent* event) override;
  
    // Méthodes de gestion interne
    void pause();
    void draw_energy();

    // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
    VueOpenGL vue;
    // Timer et temps total
    int timerId;
    double t;
    // Pour faire évoluer les objets avec le bon "dt"
    QTime chronometre;
    // Système à dessiner, faire évoluer
    Systeme* sys;
    // Tableau pour stocker les valeurs de l'énergie
    std::vector<double> tab_energy;
};

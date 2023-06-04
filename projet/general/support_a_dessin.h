#pragma once

// "Forward declaration" des classes pour pouvoir les utiliser dans SupportADessin
class Systeme;

class Masse;

class TissuS;

class SupportADessin{
 public:
  // Constructeurs et destructeur
  virtual ~SupportADessin() = default;
  // on ne copie pas les Supports
  SupportADessin(SupportADessin const&)            = delete;
  SupportADessin& operator=(SupportADessin const&) = delete;
   // mais on peut les déplacer
  SupportADessin(SupportADessin&&)            = default;
  SupportADessin& operator=(SupportADessin&&) = default;
  SupportADessin() = default;

  // Méthodes polymorphiques dessine()
  virtual void dessine(Systeme const&) = 0;

  virtual void dessine(Masse const&) = 0;

  virtual void dessine(TissuS const&) = 0;
};

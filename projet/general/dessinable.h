#pragma once

// "Forward declaration" de SupportADessin pour l'utiliser
class SupportADessin;

class Dessinable {
 public:
  // Méthodes 
  virtual void dessine_sur(SupportADessin&) = 0;

  // Constructeurs et destructeurs
  virtual ~Dessinable() = default;
  Dessinable(Dessinable const&)            = default;
  Dessinable& operator=(Dessinable const&) = default;
  Dessinable(Dessinable&&)                 = default;
  Dessinable& operator=(Dessinable&&)      = default;

  Dessinable() = default;
};

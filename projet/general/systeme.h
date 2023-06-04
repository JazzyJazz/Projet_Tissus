#pragma once

#ifndef SYSTEME_H
#define SYSTEME_H

#include <iostream>
#include <vector>

#include "dessinable.h"
#include "support_a_dessin.h"
#include "tissuS.h"
#include "contraintes.h"

class Systeme : public Dessinable{
    private:
        std::vector<TissuS*> tissus;
        std::vector<Contrainte*> contraintes;
        double temps;
        
    public:
        // Constructeurs et destructeur
        virtual ~Systeme() = default;
        Systeme(Systeme const&)            = delete;
        Systeme& operator=(Systeme const&) = delete;
        Systeme(Systeme&&)                 = default;
        Systeme& operator=(Systeme&&)      = default;

        Systeme(std::vector<TissuS*> tissus_ = {});

        // Accesseurs et manipulateurs
        std::vector<TissuS*> get_tissus() const;

        void add_tissu(TissuS* tissu);
        void add_contrainte(Contrainte* contrainte);

        // Méthodes
        virtual void dessine_sur(SupportADessin& support) override;

        void evolue(double dt);

        void affiche_masses(std::ostream& flot) const;

        double get_energy() const;
};  

// Surcharge de l'opérateur d'affichage
std::ostream& operator<<(std::ostream&, Systeme const&);

#endif
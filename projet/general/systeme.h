#pragma once

#ifndef SYSTEME_H
#define SYSTEME_H

#include <iostream>
#include <vector>

#include "dessinable.h"
#include "tissuS.h"
#include "contraintes.h"

class Systeme : public Dessinable{
    private:
        std::vector<TissuS*> tissus;
        std::vector<Contrainte*> contraintes;
        double temps;
        
    public:
        virtual ~Systeme() = default;
        Systeme(Systeme const&)            = delete;
        Systeme& operator=(Systeme const&) = delete;
        Systeme(Systeme&&)                 = default;
        Systeme& operator=(Systeme&&)      = default;

        Systeme(std::vector<TissuS*> tissus_ = {});

        virtual void dessine_sur(SupportADessin& support) override;

        std::vector<TissuS*> get_tissus() const;

        void add_tissu(TissuS* tissu);

        void evolue(double dt);

        void affiche_masses(std::ostream& flot) const;

        void add_contrainte(Contrainte* contrainte);

        double get_energy() const;
};  

std::ostream& operator<<(std::ostream&, Systeme const&);

#endif
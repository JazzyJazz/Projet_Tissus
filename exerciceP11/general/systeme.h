#pragma once

#ifndef SYSTEME_H
#define SYSTEME_H

#include <iostream>
#include <vector>

#include "dessinable.h"
#include "tissuS.h"

class Systeme : public Dessinable{
    private:
        std::vector<TissuS*> tissus;
        double angle;
    public:
        virtual ~Systeme() = default;
        Systeme(Systeme const&)            = default;
        Systeme& operator=(Systeme const&) = default;
        Systeme(Systeme&&)                 = default;
        Systeme& operator=(Systeme&&)      = default;

        Systeme(std::vector<TissuS*> = {});

        virtual void dessine_sur(SupportADessin&) override;

        std::vector<TissuS*> get_tissus() const;

        void evolue(double);

        void affiche_masses() const;

        double get_angle() const;
};

std::ostream& operator<<(std::ostream&, Systeme const&);

#endif
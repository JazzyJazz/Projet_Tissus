#pragma once

#ifndef INTEGRATEUR_H
#define INTEGRATEUR_H

#include "masse.h"

class Integrateur{
    public:
        // Méthode polymorphique evolue(), propre à chaque sous-classe
        virtual void evolve(Masse& m, double dt) const = 0;
};

class IntegrateurEulerCromer : public Integrateur{
    public:
        void evolve(Masse& m, double dt) const override;
};

class IntegrateurNewmark : public Integrateur{
    private:
        double eps;
    public:
        // Constructeur
        IntegrateurNewmark(double eps_ = 1e-6);
        
        void evolve(Masse& m, double dt) const override;
};

class IntegrateurRungeKutta : public Integrateur{
    public:
        void evolve(Masse& m, double dt) const override;
};

#endif
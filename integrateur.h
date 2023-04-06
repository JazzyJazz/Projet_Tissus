#include <string>
#include "masse.h"
#pragma once

class Integrateur{
    protected:
        std::string nom;
    public:
        virtual void evolve(Masse&, double) const = 0;
};

class IntegrateurEulerCromer : public Integrateur{
    public:
        void evolve(Masse&, double) const override;
};
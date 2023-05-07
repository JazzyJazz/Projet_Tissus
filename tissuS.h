#pragma once

#ifndef TISSUS_H
#define TISSUS_H

#include <vector>

#include "dessinable.h"
#include "masse.h"
#include "ressort.h"


struct Ressort_Temp{
    Masse* m_d;
    Masse* m_a;
    double r;
    double l0;
    Ressort_Temp(Masse*, Masse*, double, double);
};

class TissuS : public Dessinable{
    private:
        std::vector<Masse*> masses;
        std::vector<Ressort*> ressorts;
        std::vector<Ressort_Temp> ressorts_temp;

        bool check();

    public:
        TissuS(std::vector<Masse*>);

        void connecte(unsigned int, unsigned int, double, double);

        void connecte_masses();

        void maj_forces();

        void evolve(double);

        std::vector<Masse*> get_masses() const;

        std::vector<Ressort*> get_ressorts() const;

        virtual void dessine_sur(SupportADessin&) override;
};

#endif
#pragma once

#ifndef TISSU_S_H
#define TISSU_S_H
#include "masse.h"
#include "vecteur3D.h"
#include "ressort.h"
#include <vector>

struct Ressort_Temp{
    Masse* m_d;
    Masse* m_a;
    double r;
    double l0;
    Ressort_Temp(Masse*, Masse*, double, double);
};

class TissuS{
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
};

#endif
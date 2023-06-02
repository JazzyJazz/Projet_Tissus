#pragma once

#ifndef TISSUSGEO_H
#define TISSUSGEO_H

#include <vector>

#include "dessinable.h"
#include "vecteur3D.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"
#include "tissuS.h"

class TissuChaine : public TissuS{
    public:
        TissuChaine(double m_, double coeff_, double k_, double l0_, std::vector<Vecteur3D> positions_);

        virtual ~TissuChaine() = default;
};

class TissuRectangle : public TissuS{
    public:
        TissuRectangle(double m_, Vecteur3D long_, Vecteur3D larg_, Vecteur3D pos0, double coeff_, double dens_lin_, double k_, double l0_);

        virtual ~TissuRectangle() = default;
};

class TissuDisque : public TissuS{
    public:
        TissuDisque(double m_, Vecteur3D pos0, Vecteur3D ray_, double pas_rad,  double coeff_, double k_, double pas_ang = 20);

        virtual ~TissuDisque() = default;
};

class TissuCompose : public TissuS{
    private:
        double eps;
        double k;
    public:
        TissuCompose(std::vector<TissuS*>, double = 10, double = 0.1);

        virtual ~TissuCompose() = default;

        void raccommode();
};
#endif
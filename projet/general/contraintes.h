#pragma once

#ifndef CONTRAINTE_H
#define CONTRAINTE_H

#include <vector>

#include "dessinable.h"
#include "vecteur3D.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"
#include "tissuS.h"

class Contrainte{
    protected:
        Vecteur3D pos;
        double ray;
        bool isIn(Masse* m_);
    public:
        Contrainte(Vecteur3D pos_, double ray_);

        virtual void appliquer(TissuS* tissu, double temps_) = 0;

        virtual ~Contrainte() = default;
};

class Crochet : public Contrainte{
    public:
        Crochet(Vecteur3D pos_, double ray_);

        virtual void appliquer(TissuS* tissu, double temps_) override;
};

class Impulsion : public Contrainte{
    protected:
        double t_i;
        double t_f;
        Vecteur3D force;
        std::vector<Masse*> masses;
    public:
        Impulsion(Vecteur3D pos_, double ray_, double t_deb, double t_fin, Vecteur3D force_, std::vector<TissuS*> tissus_);

        virtual void appliquer(TissuS* tissu, double temps_) override;
};

class ImpulsionSin : public Impulsion{
    private:
        double freq;
        Vecteur3D f_i;
    public:
        ImpulsionSin(Vecteur3D pos_, double ray_, double t_deb, double t_fin, Vecteur3D force_i, std::vector<TissuS*> tissus_, double freq_);

        virtual void appliquer(TissuS* tissu, double temps_) override;
};

#endif
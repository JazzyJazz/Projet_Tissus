#pragma once

#ifndef CONTRAINTE_H
#define CONTRAINTE_H

#include <vector>

#include "vecteur3D.h"
#include "masse.h"
#include "tissuS.h"

class Contrainte{
    protected:
        Vecteur3D pos;
        double ray;
        bool isIn(Masse* m_);

    public:
        // Constructeurs et destructeurs
        Contrainte(Vecteur3D pos_, double ray_);

        virtual ~Contrainte() = default;

        // Méthodes
        virtual void appliquer(TissuS* tissu, double temps_) = 0;
};

class Crochet : public Contrainte{
    public:
        // Constructeur et destructeurs
        Crochet(Vecteur3D pos_, double ray_);

        // Méthodes
        virtual void appliquer(TissuS* tissu, double temps_) override;
};

class Impulsion : public Contrainte{
    protected:
        double t_i;
        double t_f;
        Vecteur3D force;
        std::vector<Masse*> masses;

    public:
        // Constructeur et destructeurs
        Impulsion(Vecteur3D pos_, double ray_, double t_deb, double t_fin, Vecteur3D force_, std::vector<TissuS*> tissus_);

        // Méthodes
        virtual void appliquer(TissuS* tissu, double temps_) override;
};

class ImpulsionSin : public Impulsion{
    private:
        double freq;
        Vecteur3D f_i;

    public:
        // Constructeur et destructeurs
        ImpulsionSin(Vecteur3D pos_, double ray_, double t_deb, double t_fin, Vecteur3D force_i, std::vector<TissuS*> tissus_, double freq_);

        // Méthodes
        virtual void appliquer(TissuS* tissu, double temps_) override;
};

#endif
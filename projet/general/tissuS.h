#pragma once

#ifndef TISSUS_H
#define TISSUS_H

#include <vector>

#include "dessinable.h"
#include "support_a_dessin.h"
#include "masse.h"
#include "ressort.h"

// Ressort temporaire = structure qui imite les ressorts, mais sans méthodes
struct Ressort_Temp{
    Masse* m_d;
    Masse* m_a;
    double r;
    double l0;
    Ressort_Temp(Masse* m_d, Masse* m_a, double k, double l0);
};

class TissuS : public Dessinable{
    protected:
        std::vector<Masse*> masses;
        std::vector<Ressort*> ressorts;
        std::vector<Ressort_Temp> ressorts_temp;
        int i;

        bool check();

    public:
        // Constructeurs et destructeur
        TissuS(std::vector<Masse*> masses_ = {});
        TissuS(TissuS&);
        virtual ~TissuS() = default;

        // Méthodes
        void connecte(unsigned int n1, unsigned int n2, double k_, double l0_);
        void connecte_masses();
        void maj_forces();
        void evolve(double dt);
        virtual void dessine_sur(SupportADessin& support) override;

        // Accesseurs
        int get_integrateur() const;
        std::vector<Masse*> get_masses() const;
        std::vector<Ressort*> get_ressorts() const;

        // Manipulateurs
        void set_integrateur(int i_);
        void set_color_vit(bool b);
};

#endif
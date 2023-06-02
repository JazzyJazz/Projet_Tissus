#pragma once

#ifndef TISSUS_H
#define TISSUS_H

#include <vector>

#include "dessinable.h"
#include "masse.h"
#include "ressort.h"
#include "integrateur.h"


struct Ressort_Temp{
    Masse* m_d;
    Masse* m_a;
    double r;
    double l0;
    Ressort_Temp(Masse*, Masse*, double, double);
};

class TissuS : public Dessinable{
    protected:
        std::vector<Masse*> masses;
        std::vector<Ressort*> ressorts;
        std::vector<Ressort_Temp> ressorts_temp;
        int i;

        bool check();

    public:
        TissuS(std::vector<Masse*> masses_ = {});
        
        TissuS(TissuS&);

        virtual ~TissuS() = default;

        void connecte(unsigned int n1, unsigned int n2, double k_, double l0_);
        void connecte_masses();
        void maj_forces();
        void evolve(double dt);

        void set_integrateur(int i_);
        std::vector<Masse*> get_masses() const;
        std::vector<Ressort*> get_ressorts() const;
        int get_integrateur() const;
        void set_color_vit(bool b);

        virtual void dessine_sur(SupportADessin& support) override;

};

#endif
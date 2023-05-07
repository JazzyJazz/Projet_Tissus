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
    public:
        Systeme(std::vector<TissuS*>);

        virtual void dessine_sur(SupportADessin&) override;

        std::vector<TissuS*> get_tissus() const;
};

std::ostream& operator<<(std::ostream&, Systeme const&);

#endif
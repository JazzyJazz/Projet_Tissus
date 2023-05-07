#pragma once

#ifndef DESSINABLE_H
#define DESSINABLE_H

#include <vector>

#include "masse.h"
#include "tissuS.h"


class Dessinable{
    public:
        virtual void dessine_sur(SupportADessin&) = 0;
};

class SupportADessin{
public:
    virtual ~SupportADessin() = default;
    virtual void dessine(TissuS const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Masse const&) = 0;
};

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
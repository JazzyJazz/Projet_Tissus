#pragma once

#ifndef DESSINABLE_H
#define DESSINABLE_H

class Masse;
class TissuS;
class Systeme;

class SupportADessin{
public:
    virtual ~SupportADessin() = default;
    virtual void dessine(TissuS const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Masse const&) = 0;
};

class Dessinable{
    public:
        virtual void dessine_sur(SupportADessin&) = 0;
};

#endif
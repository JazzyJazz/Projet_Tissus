#pragma once

#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <vector>
#include <iostream>


class Vecteur3D{
    private:
        std::vector<double> vect;
        
    public:
        // Constructeur
        Vecteur3D();

        Vecteur3D(double, double, double);

        ~Vecteur3D() = default;

        // Méthodes

        void set_coord(unsigned int, double);

        std::vector<double> get_vect() const;

        double norme2() const;

        double norme() const;

        // Opérateurs basiques

        bool operator==(Vecteur3D Vect2) const;

        Vecteur3D operator+(Vecteur3D Vect2) const;

        Vecteur3D operator-(Vecteur3D Vect2) const;

        Vecteur3D operator-() const;

        Vecteur3D operator*(double a) const;

        Vecteur3D operator/(double a) const;

        double operator*(Vecteur3D Vect2) const;

        Vecteur3D operator^(Vecteur3D Vect2) const;

        Vecteur3D operator~() const;

        // Opérateurs dérivés

        bool operator!=(Vecteur3D Vect2) const;

        Vecteur3D& operator+=(Vecteur3D Vect2);

        Vecteur3D& operator-=(Vecteur3D Vect2);

        Vecteur3D& operator*=(double a);

        Vecteur3D& operator^=(Vecteur3D Vect2);

};

std::ostream& operator<<(std::ostream&, Vecteur3D const&);

Vecteur3D operator*(double, Vecteur3D const&);

#endif
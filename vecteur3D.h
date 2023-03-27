#include <vector>
#include <cmath>
#pragma once

class Vecteur3D{
    private:
        std::vector<double> vect;
    public:
        // Constructeur

        Vecteur3D(double x = 0, double y = 0, double z = 0){
            vect.push_back(x);
            vect.push_back(y);
            vect.push_back(z);
        }

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


// Méthodes

void Vecteur3D::set_coord(unsigned int pos, double x){
    vect[pos] = x;
}

std::vector<double> Vecteur3D::get_vect() const{
    return vect;
}

double Vecteur3D::norme2() const{
    return (*this)*(*this);
}

double Vecteur3D::norme() const{
    return sqrt(norme2());
}

// Opérateurs externes

std::ostream& operator<<(std::ostream& sortie, Vecteur3D& Vect2){
    sortie << "(" << Vect2.get_vect()[0] << ", " << Vect2.get_vect()[1] << ", " << Vect2.get_vect()[2] << ")" << std::endl;
    return sortie;
}

Vecteur3D operator*(double a, Vecteur3D& Vect2){
    return Vect2*a;
}


// Opérateurs internes

// Opérateurs basiques

bool Vecteur3D::operator==(Vecteur3D Vect2) const{
    for(int i(0); i < vect.size(); i++){
        if(vect[i] != Vect2.vect[i]){
            return false;
        }
    }
    return true;
}

Vecteur3D Vecteur3D::operator+(Vecteur3D Vect2) const{
    return Vecteur3D(vect[0]+Vect2.vect[0], vect[1]+Vect2.vect[1], vect[2]+Vect2.vect[2]);
}

Vecteur3D Vecteur3D::operator-(Vecteur3D Vect2) const{
    return Vecteur3D(vect[0]-Vect2.vect[0], vect[1]-Vect2.vect[1], vect[2]-Vect2.vect[2]);
}

Vecteur3D Vecteur3D::operator-() const{
    return Vecteur3D(-vect[0], -vect[1], -vect[2]);
}

Vecteur3D Vecteur3D::operator*(double a) const{
    return Vecteur3D(a*vect[0], a*vect[1], a*vect[2]);
}

double Vecteur3D::operator*(Vecteur3D Vect2) const{
    return vect[0]*Vect2.vect[0] + vect[1]*Vect2.vect[1] + vect[2]*Vect2.vect[2];
}

Vecteur3D Vecteur3D::operator^(Vecteur3D Vect2) const{
    return Vecteur3D(vect[1]*Vect2.vect[2]-vect[2]*Vect2.vect[1], vect[2]*Vect2.vect[0]-vect[0]*Vect2.vect[2], vect[0]*Vect2.vect[1]-vect[1]*Vect2.vect[0]);
}

Vecteur3D Vecteur3D::operator~() const{
    return (*this)*(1.0/norme());
}

// Opérateurs dérivés

bool Vecteur3D::operator!=(Vecteur3D Vect2) const{
    return not(*this == Vect2);
}

Vecteur3D& Vecteur3D::operator+=(Vecteur3D Vect2){
    return *this = *this + Vect2;
}

Vecteur3D& Vecteur3D::operator-=(Vecteur3D Vect2){
    return *this = *this - Vect2;
}

Vecteur3D& Vecteur3D::operator*=(double a){
    return *this = *this * a;
}

Vecteur3D& Vecteur3D::operator^=(Vecteur3D Vect2){
    return *this = (*this ^ Vect2);
}
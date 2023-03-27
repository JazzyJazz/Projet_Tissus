#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Vecteur3D{
    private:
        vector<double> vect;
    public:
        Vecteur3D(double x = 0, double y = 0, double z = 0){
            vect.push_back(x);
            vect.push_back(y);
            vect.push_back(z);
        }

        void set_coord(unsigned int pos, double x){
            vect[pos] = x;
        }

        void affiche() const{
            cout << "(" << vect[0] << ", " << vect[1] << ", " << vect[2] << ")" << endl;
        }

        bool compare(Vecteur3D Vect2){
            for(int i(0); i < vect.size(); i++){
                if(vect[i] != Vect2.vect[i]){
                    return false;
                }
            }
            return true;
        }

        vector<double> get_vect(){
            return vect;
        }

        // Opérations

        Vecteur3D add(Vecteur3D Vect2) const{
            return Vecteur3D(vect[0]+Vect2.vect[0], vect[1]+Vect2.vect[1], vect[2]+Vect2.vect[2]);
        }

        Vecteur3D soust(Vecteur3D Vect2) const{
            return Vecteur3D(vect[0]-Vect2.vect[0], vect[1]-Vect2.vect[1], vect[2]-Vect2.vect[2]);
        }

        Vecteur3D opp() const{
            return Vecteur3D(-vect[0], -vect[1], -vect[2]);
        }

        Vecteur3D mult(double a) const{
            return Vecteur3D(a*vect[0], a*vect[1], a*vect[2]);
        }

        double prod_scal(Vecteur3D Vect2) const{
            return vect[0]*Vect2.vect[0] + vect[1]*Vect2.vect[1] + vect[2]*Vect2.vect[2];
        }

        Vecteur3D prod_vect(Vecteur3D Vect2) const{
            return Vecteur3D(vect[1]*Vect2.vect[2]-vect[2]*Vect2.vect[1], vect[2]*Vect2.vect[0]-vect[0]*Vect2.vect[2], vect[0]*Vect2.vect[1]-vect[1]*Vect2.vect[0]);
        }

        double norme2() const{
            return prod_scal(*this);
        }

        double norme() const{
            return sqrt(norme2());
        }

        Vecteur3D unitaire() const{
            return mult(1.0/norme())
        }
};
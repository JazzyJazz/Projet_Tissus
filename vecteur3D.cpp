#include <iostream>
#include <vector>
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
};
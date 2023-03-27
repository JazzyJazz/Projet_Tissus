
class Vecteur3D{
    private:
        vector<double> coord;
    public:
        Vecteur3D(double x = 0, double y = 0, double z = 0){
            coord.push_back(x);
            coord.push_back(y);
            coord.push_back(z);
        }

        void set_coord(unsigned int pos, double x){
            coord[pos] = x;
        }

        void affiche() const{
            std::cout << "(" << coord[0] << ", " << coord[1] << ", " << coord[2] << ")" << endl;
        }

        bool compare(Vecteur3D vect2){
            for(int i(0); i < coord.size(); i++){
                if(coord[i] != vect2.coord[i]){
                    return false;
                }
            }
            return true;
        }
};
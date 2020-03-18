#ifndef DEF_CVECT
#define DEF_CVECT

#include <iostream>

class CVect {
public:
    CVect();
    CVect(CVect const& copyVect);
    CVect(int nN, double* ptab);
    ~CVect();

    CVect somme(CVect const& vect) const;
    double prod_scal(CVect const& vect) const;

    CVect& operator=(CVect const& copyVect);
    CVect operator+(CVect const& vector) const;
    double operator*(CVect const& vector) const;

    friend std::ostream& operator<<(std::ostream& out, CVect const& self);

private:
    int m_nN; //taille d'un vecteur
    double* m_ptab; //composantes d'un vecteur
};

#endif
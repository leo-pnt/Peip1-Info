#ifndef DEF_CVECT
#define DEF_CVECT

#include <iostream>

class CVect {
public:
    CVect();
    CVect(int);
    CVect(CVect const&);
    CVect(int, double*);
    ~CVect();

    CVect somme(CVect const&) const;
    double prod_scal(CVect const&) const;

    CVect& operator=(CVect const&);
    CVect operator+(CVect const&) const;
    double operator*(CVect const&) const;
    double operator[](int) const;

    friend std::ostream& operator<<(std::ostream&, CVect const&);

    void ecrit_bin(string); //donner le nom de fichier
    void lit_bin(string); //donner le nom de fichier

private:
    int m_nN; //taille d'un vecteur
    double* m_ptab; //composantes d'un vecteur
};

#endif
#ifndef DEF_CTAB2D
#define DEF_CTAB2D

#include <iostream>

class CTab2D {
public:
    CTab2D();
    CTab2D(CTab2D const& cpy);
    CTab2D(int, int, double);
    ~CTab2D();

    void afficher(std::ostream&) const;
    void fillRand();

    double operator()(int, int) const;
    double* operator[](int) const;

    friend std::ostream& operator<<(std::ostream&, CTab2D const&);

private:
    double** m_ptab = NULL; //tableau 2D
    int m_nbLigne = 0;
    int m_nbColonne = 0;
};

#endif
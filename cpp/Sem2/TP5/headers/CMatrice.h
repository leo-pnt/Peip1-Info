#ifndef DEF_CMATRICE
#define DEF_CMATRICE

#include <iostream>

class CMatrice{
public:
    CMatrice();
    CMatrice(CMatrice const&); //constructeur copie
    CMatrice(int, int, int**); //associer une matrice existante
    CMatrice(int, int, int); //donner la même valeur à toutes les cases
    ~CMatrice();

    CMatrice operator=(CMatrice const&);
    CMatrice operator+(CMatrice const&);
    CMatrice operator*(int const&);
    CMatrice operator*(CMatrice const&);
    
    friend std::ostream& operator<<(std::ostream &, CMatrice const&);
    friend std::istream& operator>>(std::istream &, CMatrice &);

private:
    int** m_ptab;
    int m_l; //nb lignes
    int m_c; //nb colonnes

};

#endif
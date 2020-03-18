#ifndef DEF_CPROMO
#define DEF_CPROMO

#include <iostream>
#include "CEleve.h"

class CPromo{
public:
    CPromo();
    CPromo(int nbEleve);
    ~CPromo();

    friend std::istream& operator>>(std::istream& in, CPromo & self);
    friend std::ostream& operator<<(std::ostream& out, CPromo const& self);

    void ecriture(std::string nomFichier);
    void lecture(std::string nomFichier);

private:
    CEleve* m_eleve;
    int m_nbEleve;
};

#endif
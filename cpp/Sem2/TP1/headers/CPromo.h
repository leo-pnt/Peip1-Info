#ifndef DEF_CPROMO
#define DEF_CPROMO

#include <iostream>
#include "CEleve.h"

class CPromo{
public:
    CPromo();
    CPromo(int nbEleve);
    ~CPromo();

    friend std::ostream& operator<<(std::ostream& out, CPromo const& self);

private:
    CEleve* m_eleve;
    int m_nbEleve;
};

#endif
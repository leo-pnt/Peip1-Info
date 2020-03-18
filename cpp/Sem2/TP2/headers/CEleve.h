#ifndef DEF_CELEVE
#define DEF_CELEVE

#include <iostream>
#include "CIndividu.h"

class CEleve{
public:
    CEleve();
    CEleve(string nom, int age, int nbNote, double* note);
    ~CEleve();

    int get_m_nbNote();

    friend std::ostream& operator<<(std::ostream& out, CEleve const& self);
    friend std::istream& operator>>(std::istream& in, CEleve& self);

    friend std::ofstream& operator<<(std::ofstream& outStream, CEleve const& self);
    friend std::ifstream& operator>>(std::ifstream& inStream, CEleve & self);

private:
    CIndividu* m_individu;
    double* m_note;
    int m_nbNote;
};

#endif
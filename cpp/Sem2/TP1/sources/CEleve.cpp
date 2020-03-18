#include <iostream>
using namespace std;
#include "CEleve.h"

CEleve::CEleve()
{
    m_individu = new CIndividu();
}

CEleve::CEleve(string nom, int age, int nbNote, double* note):
m_individu(0), m_nbNote(nbNote)
{
    m_individu = new CIndividu(nom, age);
    m_note = new double[m_nbNote];
    m_note = note;
}

CEleve::~CEleve()
{
    delete m_individu;
    delete[] m_note;
}

ostream& operator<<(ostream& out, CEleve const& self)
{
    out << *self.m_individu;

    for(int i = 0; i < self.m_nbNote; i++)
        out << "note[" << i << "] : " << self.m_note[i] << endl;
    
    return out;
}

istream& operator>>(istream& in, CEleve& self)
{
    in >> *self.m_individu;
    cout << "nombre de notes? >> ";
    in >> self.m_nbNote;
    
    self.m_note = new double[self.m_nbNote];

    for(int i = 0; i < self.m_nbNote; i++)
    {
        cout << "note[" << i << "]? >> ";
        in >> self.m_note[i];
    }

    return in;
}
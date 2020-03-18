#include <iostream>
using namespace std;
#include <fstream>
#include "CPromo.h"

CPromo::CPromo(): m_nbEleve(0) {}

CPromo::CPromo(int nbEleve):m_nbEleve(nbEleve)
{
    m_eleve = new CEleve[m_nbEleve];
}

CPromo::~CPromo()
{
    delete[] m_eleve;
}

void CPromo::ecriture(string nomFichier)
{
    ofstream outF(nomFichier.c_str());

    outF << m_nbEleve << endl;

    for(int i = 0; i < m_nbEleve; i++)
        outF << m_eleve[i];
    
    outF.close();
}

void CPromo::lecture(string nomFichier)
{
    ifstream inF(nomFichier.c_str());

    if(m_nbEleve == 0)
    {
        inF >> m_nbEleve;
        m_eleve = new CEleve[m_nbEleve];
    }
    
    else
    {
        inF >> m_nbEleve;
    }

    for(int i = 0; i < m_nbEleve; i++)
        inF >> m_eleve[i];
    
    inF.close();
}

istream& operator>>(istream& in, CPromo & self)
{
    for(int i = 0; i < self.m_nbEleve; i++)
    {
        cout << "[ELEVE (" << i << ")] :" << endl;
        in >> self.m_eleve[i];
    }

    return in;
}

ostream& operator<<(ostream& out, CPromo const& self)
{
    cout << "\n[Liste des eleves de la promo]:\n";

    for(int i = 0; i < self.m_nbEleve; i++)
        out << self.m_eleve[i];
    
    return out;
}
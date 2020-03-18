#include <iostream>
using namespace std;
#include "CPromo.h"

CPromo::CPromo(): m_nbEleve(0) {}

CPromo::CPromo(int nbEleve):m_nbEleve(nbEleve)
{
    m_eleve = new CEleve[m_nbEleve];
    for(int i = 0; i < m_nbEleve; i++)
    {
        cout << "[ELEVE (" << i << ")] :" << endl;
        cin >> m_eleve[i];
    }
}

CPromo::~CPromo()
{
    delete[] m_eleve;
}

ostream& operator<<(ostream& out, CPromo const& self)
{
    cout << "\n[Liste des eleves de la promo] :\n";

    for(int i = 0; i < self.m_nbEleve; i++)
        out << self.m_eleve[i];
    
    return out;
}
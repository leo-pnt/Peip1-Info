#include <iostream>
using namespace std;
#include "CEleve.h"
#include <fstream>

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

int CEleve::get_m_nbNote()
{
    return m_nbNote;
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

ofstream& operator<<(ofstream& outStream, CEleve const& self)
{
    if(outStream)
    {
        outStream << *self.m_individu;
        outStream << self.m_nbNote << "\n";
        for(int i  = 0; i < self.m_nbNote; i++)
            outStream << self.m_note[i] << "\n";
    }
    
    else
    {
        cout << "ERREUR. Impossible d'ouvrir le fichier." << endl;
    }
    
    return outStream;
}

ifstream& operator>>(ifstream& inStream, CEleve & self)
{
    if(inStream)
    {
        inStream >> *self.m_individu;
        inStream >> self.m_nbNote;

        self.m_note = new double[self.m_nbNote];

        for(int i = 0; i < self.m_nbNote; i++)
            inStream >> self.m_note[i];
    }

    else
    {
        cout << "ERREUR. Impossible d'ouvir le fichier. debug: CEleve.cpp" << endl;
    }
    
    
    return inStream;
}

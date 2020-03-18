#include <iostream>
using namespace std;
#include <fstream>
#include "CIndividu.h"

string const individuFileName("individu.txt");

CIndividu::CIndividu():
m_nom("none"), m_age(0)
{
}

CIndividu::CIndividu(string nom, int age):
m_nom(nom), m_age(age) {}

CIndividu::~CIndividu() {}

ostream& operator<<(ostream& out, CIndividu const& self)
{
    out << "-----" << endl;
    out << "nom : " << self.m_nom << "\nage : " << self.m_age << endl;
    return out;
}

istream& operator>>(istream& in, CIndividu& self)
{
    cout << "nom? >> ";
    in >> self.m_nom;
    cout << "age? >> ";
    in >> self.m_age;

    return in;
}

ofstream& operator<<(ofstream& outStream, CIndividu const& self)
{
    if(outStream)
    {
        outStream << self.m_nom << "\n" << self.m_age << endl;
    }

    else
    {
        cout << "ERREUR. Impossible d'ouvrir le fichier." << endl;
    }
    
    return outStream;
}

ifstream& operator>>(ifstream& inStream, CIndividu & self)
{
    if(inStream)
    {
        inStream >> self.m_nom;
        inStream >> self.m_age;
    }

    else
    {
        cout << "ERREUR. Impossible d'ouvir le fichier. debug: CIndividu.cpp" << endl;
    }
    
    
    return inStream;
}
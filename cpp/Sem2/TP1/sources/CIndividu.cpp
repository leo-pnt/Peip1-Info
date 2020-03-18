#include <iostream>
using namespace std;
#include "CIndividu.h"

CIndividu::CIndividu():
m_nom("none"), m_age(0)
{
}

CIndividu::CIndividu(string nom, int age):
m_nom(nom), m_age(age) {}

CIndividu::~CIndividu() {}

ostream& operator<<(ostream& out, CIndividu const& self)
{
    out << "----------------------------";
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
#include <iostream>
using namespace std;
#include "CVect.h"

CVect::CVect(): m_nN(5)
{
    m_ptab = new double[m_nN];
    for(int i = 0; i < m_nN; i++)
        m_ptab[i] = 0;
}

CVect::CVect(CVect const& copyVect): m_nN(copyVect.m_nN)
{
    m_ptab = new double[m_nN];

    for(int i = 0; i < m_nN; i++)
        m_ptab[i] = copyVect.m_ptab[i];
}

CVect::CVect(int nN, double* ptab): m_nN(nN), m_ptab(ptab) {}

CVect::~CVect()
{
    delete[] m_ptab;
}

CVect CVect::somme(CVect const& vect) const
{
    //(X,X,...,X) + (Y,Y) = (X+Y, X+Y, ... , X)

    if(m_nN <= vect.m_nN)
    {
        CVect vectS(vect); //on ne peux pas modifier vect directement car const&

        for(int i = 0; i < vectS.m_nN; i++)
            vectS.m_ptab[i] += m_ptab[i];

        return vectS;
    }

    else
    {
        CVect vectS(*this); //on copie l'objet de la class lui-même

        for(int i = 0; i < vectS.m_nN; i++)
            vectS.m_ptab[i] += vect.m_ptab[i];

        return vectS;
    }
}

double CVect::prod_scal(CVect const& vect) const
{
    double scal(0); //il s'agit d'une somme de produits

    //les vecteurs doivent avoir la même dimmension
    if(m_nN == vect.m_nN)
    {
        for(int i = 0; i < vect.m_nN; i++)
            scal += m_ptab[i] * vect.m_ptab[i];
    }

    else
        cout << "ERREUR. Les vecteurs n'ont pas la meme dimmension." << endl;
    
    return scal;
}

CVect& CVect::operator=(CVect const& copyVect)
{
    if(this != &copyVect)
    //On vérifie que l'objet n'est pas le même que celui reçu en argument
    {
        m_nN = copyVect.m_nN; //On copie tous les champs

        delete[] m_ptab; //on supprime les anciennes composantes

        m_ptab = new double[m_nN]; //on copie les nouvelles
        for(int i = 0; i < m_nN; i++)
            m_ptab[i] = copyVect.m_ptab[i];
    }
    return *this; //On renvoie l'objet lui-même
}

CVect CVect::operator+(CVect const& vector) const
{
    return somme(vector);
}

double CVect::operator*(CVect const& vector) const
{
    return prod_scal(vector);
}

ostream& operator<<(ostream& out, CVect const& self)
{
    //on affiche (X1,X2,...,Xn)
    out << "(";
    for(int i = 0; i < self.m_nN; i++)
    {
        if(i < self.m_nN - 1)
            out << self.m_ptab[i] << ",";
        else
            out << self.m_ptab[i];
        
    }
    out << ")";

    return out;
}
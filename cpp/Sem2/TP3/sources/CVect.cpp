#include <iostream>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
#include "CVect.h"

CVect::CVect(): m_nN(5)
{
    m_ptab = new double[m_nN];
    for(int i = 0; i < m_nN; i++)
        m_ptab[i] = 0;
}

CVect::CVect(int nN): m_nN(nN)
{
    srand(time(NULL));

    m_ptab = new double[m_nN];
    for(int i = 0; i < m_nN; i++)
    {
        //nombre aléatoire entre -10 et 10
        m_ptab[i] = rand()%11 - rand()%11;
    }
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
        CVect vectS(*this); //on copie l'objet lui-même

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
    //on vérifie que l'objet n'est pas le même que celui reçu en argument
    {
        m_nN = copyVect.m_nN; //on copie tous les champs

        delete[] m_ptab; //on supprime les anciennes composantes

        m_ptab = new double[m_nN]; //on copie les nouvelles
        for(int i = 0; i < m_nN; i++)
            m_ptab[i] = copyVect.m_ptab[i];
    }
    return *this; //on renvoie l'objet lui-même
}

CVect CVect::operator+(CVect const& vector) const
{
    return somme(vector);
}

double CVect::operator*(CVect const& vector) const
{
    return prod_scal(vector);
}

double CVect::operator[](int i) const
{
    return m_ptab[i];
}

ostream& operator<<(ostream& out, CVect const& self)
{
    //on affiche (X1,X2,...,Xn)
    out << "(";
    for(int i = 0; i < self.m_nN; i++)
    {
        if(i < self.m_nN - 1) //-1 car on ne veut pas : ...,Xn,)  mais plutôt : ...,Xn)
            out << self.m_ptab[i] << ",";
        else
            out << self.m_ptab[i];
        
    }
    out << ")";

    return out;
}

void CVect::ecrit_bin(string filename)
{
    ofstream f;

    if(f)
    {
        f.open(filename.c_str(), ios::out|ios::binary);
        f.write((char*) & m_nN, sizeof(m_nN));
        for(int i = 0; i < m_nN; i++)
            f.write((char*) & m_ptab[i], sizeof(m_ptab[i]));
        
        f.close();
    }

    else
        cout << "ERREUR. Impossible d'ouvir le fichier." << endl;
}

void CVect::lit_bin(string filename)
{
    ifstream f;
    if(f)
    {
        f.open(filename.c_str(), ios::in|ios::binary);
        f.read((char*) & m_nN, sizeof(m_nN));

        //on supprime les anciennes valeurs
        delete[] m_ptab;
        //on laisse la place pour les nouvelles
        m_ptab = new double[m_nN];

        for(int i = 0; i < m_nN; i++)
            f.read((char*) & m_ptab[i], sizeof(m_ptab[i]));
        f.close();
    }

    else
    {
        cout << "ERREUR. Impossible d'ouvrir le fichier." << endl;
    }
}
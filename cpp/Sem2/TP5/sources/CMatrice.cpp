#include <iostream>
using namespace std;

#include "CMatrice.h"

CMatrice::CMatrice(): m_l(1), m_c(1)
{
    m_ptab = new int*[m_l];
    for(int i = 0; i < m_l; i++)
        m_ptab[i] = new int[m_c];
    
    //on initialise à 0
    for(int i = 0; i < m_l; i++)
    {
        for(int j = 0; j < m_c; j++)
        {
            m_ptab[i][j] = 0;
        }
    }
}

CMatrice::CMatrice(CMatrice const& mat): m_l(mat.m_l), m_c(mat.m_c)
{
    m_ptab = new int*[m_l];
    for(int i = 0; i < m_l; i++)
    {
        m_ptab[i] = new int[m_c];
        for(int j = 0; j < m_c; j++)
        {
            m_ptab[i][j] = mat.m_ptab[i][j];
        }
    }
}

CMatrice::CMatrice(int l, int c, int** ptab): m_l(l), m_c(c), m_ptab(ptab)
{

}

CMatrice::CMatrice(int l, int c, int val): m_l(l), m_c(c)
{
    m_ptab = new int*[m_l];
    for(int i = 0; i < m_l; i++)
    {
        m_ptab[i] = new int[m_c];
        for(int j = 0; j < m_c; j++)
        {
            //on affecte les valeurs selon "val"
            m_ptab[i][j] = val;
        }
    }
}

CMatrice::~CMatrice()
{
    for(int i = 0; i < m_c; i++)
    {
        delete[] m_ptab[i];
    }
    delete[] m_ptab;
}


CMatrice CMatrice::operator=(CMatrice const& mat)
{
    //on supprime les anciennes valeurs
    for(int i = 0; i < m_l; i++)
        delete[] m_ptab[i];
    delete[] m_ptab;

    //on copie les nouvelles valeurs
    m_ptab = new int*[m_l];
    for(int i = 0; i < m_l; i++)
    {
        m_ptab[i] = new int[m_c];
        for(int j = 0; j < m_c; j++)
        {
            m_ptab[i][j] = mat.m_ptab[i][j];
        }
    }

    return *this;
}

CMatrice CMatrice::operator+(CMatrice const& matrice)
{
    //on veut que les matrices aient les même nb de colonnes et lignes
    if(m_l == matrice.m_l && m_c == matrice.m_c)
    {
        CMatrice Sum(m_l, m_c, 0); //on créer la matrice somme
        for(int i = 0; i < Sum.m_l; i++)
        {
            for(int j = 0; j < Sum.m_c; j++)
            {
                Sum.m_ptab[i][j] = m_ptab[i][j] + matrice.m_ptab[i][j];
            }
        }

        return Sum;
    }

    else
    {
        cout << "Erreur. Les matrices n'ont pas les memes tailles" << endl;
        CMatrice voidMat(0,0,0);
        return voidMat;
    }
}

CMatrice CMatrice::operator*(int const& L)
{
    CMatrice prod(*this); //on copie la matrice

    for(int i = 0; i < m_l; i++)
    {
        for(int j = 0; j < m_c; j++)
        {
            prod.m_ptab[i][j] *= L;
        }
    }

    return prod;
}

CMatrice CMatrice::operator*(CMatrice const& matrice)
{
    if(m_c == matrice.m_l)
    {
        CMatrice prod(m_l, matrice.m_c, 0);

        for(int x = 0; x < m_l; x++)
        {
            for(int y = 0; y < matrice.m_c; y++)
            {
                for(int z = 0; z < m_c; z++) //z --> incrément permet la somme entre les lignes et colonnes
                {
                    prod.m_ptab[x][y] += m_ptab[x][z] * matrice.m_ptab[z][y];
                }
                cout << "debug: prod.mptab[" << x << "][" << y << "]: " << prod.m_ptab[x][y] << endl;
            }
        }

        return prod;
    }

    else
    {
        cout << "Erreur. Les matrices n'ont pas la meme taille" << endl;
        CMatrice voidMat(0,0,0);
        return voidMat;
    }
    
}

ostream& operator<<(ostream& os, CMatrice const& self)
{
    for(int i = 0; i < self.m_l; i++)
    {
        for(int j = 0; j < self.m_c; j++)
        {
            os << self.m_ptab[i][j] << " ";
        }
        if(i != self.m_l - 1) os << endl; //on saute pas de ligne après la dernière ligne de la matrice
    }

    return os;
}

istream& operator>>(istream& is, CMatrice & self)
{
    //on supprime les valeurs
    for(int i = 0; i < self.m_c; i++)
    {
        delete[] self.m_ptab[i];
    }
    delete[] self.m_ptab;

    //on demande la taille de la nouvelle matrice
    cout << "nb de ligne: ";
    cin >> self.m_l;

    cout << "nb de colonne: ";
    cin >> self.m_c;

    //on alloue la memoire pour les nouvelles valeurs
    self.m_ptab = new int*[self.m_l];
    for(int i = 0; i < self.m_l; i++)
        self.m_ptab[i] = new int[self.m_c];

    //on demande les nouvelles valeurs
    for(int i = 0; i < self.m_l; i++)
    {
        for(int j = 0; j < self.m_c; j++)
        {
            cout << "tab[" << i << "][" << j << "]: ";
            is >> self.m_ptab[i][j];
        }
    }

    return is;
}
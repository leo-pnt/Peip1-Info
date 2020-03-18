#include <iostream>
using namespace std;

#include <time.h>
#include <stdlib.h>

#include "CTab2D.h"

CTab2D::CTab2D(): m_nbLigne(1), m_nbColonne(1)
{
    m_ptab = new double*[m_nbLigne];
    for(int i = 0; i < m_nbLigne; ++i)
        m_ptab[i] = new double[m_nbColonne];
}

CTab2D::CTab2D(CTab2D const& cpy)
{
    cout << "debug: " << m_nbColonne << endl;
    //on detruit l'ancien tableau

    if(m_ptab != NULL)
    {
        for(int j = 0; j < m_nbColonne; j++)
            if(m_ptab[j] != NULL)
                delete[] m_ptab[j];
        delete[] m_ptab;
    }

    //on copie les paramètres
    m_nbLigne = cpy.m_nbLigne;
    m_nbColonne = cpy.m_nbColonne;

    
    //on alloue la nouvelle memoire
    m_ptab = new double*[m_nbLigne];
    for(int i = 0; i < m_nbLigne; ++i)
        m_ptab[i] = new double[m_nbColonne];
    
    //on copie les valeurs dans le nouveau tableaux
    for(int i = 0; i < m_nbLigne; i++)
        for(int j = 0; j < m_nbColonne; j++)
            m_ptab[i][j] = cpy.m_ptab[i][j];
}

CTab2D::CTab2D(int ligne, int colonne, double val): m_nbLigne(ligne), m_nbColonne(colonne)
{
    m_ptab = new double*[m_nbLigne];
    for(int i = 0; i < m_nbLigne; ++i)
        m_ptab[i] = new double[m_nbColonne];
    
    for(int i = 0; i < m_nbLigne; i++)
    {
        for(int j = 0; j < m_nbColonne; j++)
        {
            m_ptab[i][j] = val;
        }
    }
}

CTab2D::~CTab2D()
{
    for(int j = 0; j < m_nbColonne; j++)
        delete[] m_ptab[j];
    delete[] m_ptab;
}

void CTab2D::afficher(ostream& os) const
{
    os << "   ";
    for(int c = 0; c < m_nbColonne; c++)
        os << "[" << c << "]";
    os << endl;
    for(int i = 0; i < m_nbLigne; i++)
    {
        os << "[" << i << "] ";
        for(int j = 0; j < m_nbColonne; j++)
        {
            os << m_ptab[i][j] << "  ";
        }
        if(i != m_nbLigne -1)
            os << endl;
    }
}

void CTab2D::fillRand()
{
    srand(time(NULL));
    for(int i = 0; i < m_nbLigne; i++)
    {
        for(int j = 0; j < m_nbColonne; j++)
        {
            m_ptab[i][j] = rand()%2;
        }
    }
}

double* CTab2D::operator[](int i) const
{
    double* tab = new double[m_nbColonne];
    for(int j = 0; j < m_nbColonne; j++)
    {
        tab[j] = m_ptab[i][j];
    }

    return tab;
}

double CTab2D::operator()(int i, int j) const
{
    if(i < m_nbLigne && j < m_nbColonne)
    {
        return m_ptab[i][j];
    }

    else
    {
        cout << "Erreur. Valeur inaccessible. ";
        return -1;
    }
}

ostream& operator<<(ostream& os, CTab2D const& self)
{
    self.afficher(os);
    return os;
}
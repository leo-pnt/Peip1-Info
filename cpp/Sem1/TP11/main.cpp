#include <iostream>
using namespace std;

class CPolynome
{
public :
    CPolynome()
    {
        /*on demande les coeffs à l'utilisateur*/
        
        cout << "nb de coeffs du polynome >>> ";
        cin >> m_NC;
        
        for(int i = 0; i < m_NC; i++)
        {
            cout << "a" << i << " >>> ";
            cin >> m_C[i];
        }
    }
    
    //CPolynome(,) constructeur paramétré à faire
    
    double Valeur(double x)
    {
        /*on calcule P(x)*/
        double S(0); //Somme des termes du polynome
        
        return S;
    }
    
    void Afficher()
    {
        cout << "P(x) =";
        for(int i = 0; i < m_NC; i++) //on affiche chaque terme et son coeffs
        {
            //cas où la puissance est superieur à 1 et coeff non nul ou != 1 ou -1:
            if(m_C[i] != 0 && m_C[i] != 1 && m_C[i] != -1 && (m_NC-1) - i != 0 && (m_NC-1) - i != 1)
            {
                //le coeff est negatif :
                if(m_C[i] < 0) cout << " -" << -m_C[i] << ".x^" << (m_NC-1) - i;
                //le coeff est positif
                else cout << " +" << m_C[i] << ".x^" << (m_NC-1) - i;
            }
            
            //cas ou la puissance est 1 ou 0:
            else if((m_NC - 1) - i == 0 || (m_NC - 1) - i == 1)
            {
                //la puissance vaut 0:
                if((m_NC-1) - i == 0)
                {
                    //le coeff est negatif:
                    if(m_C[i] < 0) cout << " -" << -m_C[i];
                    //le coeff est positif:
                    if(m_C[i] > 0) cout << " +" <<  m_C[i];
                }
                //la puissance vaut 1:
                else
                {
                    //le coeff est negatif:
                    if(m_C[i] < 0) cout << " -" << -m_C[i] << ".x";
                    //le coeff est positif:
                    if(m_C[i] > 0) cout << " +" <<  m_C[i] << ".x";
                }
            }
            
            //cas ou le coeff vaut 1 ou -1
            else
            {
                //le coeff est negatif :
                if(m_C[i] < 0) cout << " -x^" << (m_NC-1) - i;
                //le coeff est positif
                else cout << " +x^" << (m_NC-1) - i;
            }
        }
        cout << endl;
    }
    
private:
    double m_C[10]; //stockage des coeffs du polynôme
    int m_NC; //nombre de coeffs du polynôme
};

//---------------------------

int main()
{
    cout << "[CPolynome]\nDe la forme P(x) = a0.x^10 + a1.x^9 + ... + a9.x + a10" << endl << endl;
    
    CPolynome monPolynome; //création d'un polynôme par défaut
    
    monPolynome.afficher();
    return 0;
}

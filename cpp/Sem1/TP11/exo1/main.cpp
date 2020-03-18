#include <iostream>
#include <math.h>
using namespace std;

class CPolynome
{
public :
    //costructeur par defaut
    CPolynome() : m_NC(10) {
        for(int i = 0; i < m_NC; i++){
            cout << "coeff x[" << i << "] ? ";
            cin >> m_C[i];
        }
    }
    
    //constructeur surchargé
    CPolynome(double coeff[], int NC) : m_NC(NC) {
        for(int i = 0; i < m_NC; i++) m_C[i] = coeff[i];
    }
    
    //destructeur
    ~CPolynome() {}
    
    void Affiche() {
        cout << "(" <<m_C[0]<< ")*x^"<<m_NC-1;
        for (int i=1;i<m_NC;i++)
        {
        if (m_C[i] != 0) cout << " + (" << m_C[i] << ")*x^" << m_NC-(i+1);
        }
        cout << endl;
    }
    
    double Valeur(double x) {
        double sum = 0;
        double membre; //ex : a * x^2
        for (int i=0;i<m_NC;i++)
        {
            membre = m_C[i] * pow(x,m_NC-i);
            sum += membre;
        }
        return sum;
    }
    
    CPolynome Primitive(double cste)
    {
        for(int i = 0; i < m_NC; i++)
        {
             += 1; //la puissance augmente de 1
            m_C[i] *= m_NC - i; //on primitive chaque membre
        }
        return 0;
    }
    
private :
    double m_C[10];
    int m_NC; //nombre de coeff du polynome
};



int main()
{
    CPolynome poly;
    //double valeur[20];
    //double tab[10] = {0,2,3.43,3,54.3,6,1,19,23,2.34};
    //CPolynome polynome(tab, 5);
    cout <<endl<< "[Affichage]" << endl;
    poly.Affiche();
    
    cout << endl;
    //cout << poly.Valeur(2.3) << endl;
    for(int i =0; i<=20;i++)
    {
        cout << 0.25*i << "  " << poly.Valeur(0.25*i) << endl;
    }
    cout << endl;
    
    return 0;
}

#include <iostream>
#include <math.h>
using namespace std;

class CComplexe
{
public:
    
    CComplexe() : m_dx(0), m_dy(0) {}; //constructeur par default
    CComplexe(double Re, double Im) : m_dx(Re), m_dy(Im) {}; //constructeur parametre
    ~CComplexe() {}; //destructeur
    
    void afficher() {
    if(m_dy == 0) cout << m_dx << endl;
    else if(m_dy < 0) cout << m_dx << " - " << -m_dy << "i" << endl;
    else cout << m_dx << " + " << m_dy << "i" << endl;
    }
    double getRe() const {return m_dx;}
    double getIm() const {return m_dy;}
    
    
    double module() {
        return sqrt(pow(m_dx, 2)+pow(m_dy,2));
    }
    
private:
    
    double m_dx;
    double m_dy;
};

CComplexe somme(CComplexe z1, CComplexe z2)
{
    
    return CComplexe (z1.getRe()+z2.getRe(), z1.getIm()+z2.getIm());
}

CComplexe mul(CComplexe z1, CComplexe z2)
{
    double mul_real = z1.getRe()*z2.getRe() - z1.getIm()*z2.getIm();
    double mul_imag = z1.getRe()*z2.getIm() + z1.getIm()*z2.getRe();
    
    return CComplexe(mul_real, mul_imag);
}

CComplexe operator+(CComplexe const& a, CComplexe const &b)
{
    return CComplexe (a.getRe()+b.getRe(), a.getIm()+b.getIm());
    
}

int main()
{
    
    CComplexe Zmul;
    CComplexe Z1(1,2);
    CComplexe Z2(1,2);
    CComplexe Zsum = Z1 +Z2;
    
    //Zsum = somme(Z1, Z2);
    Zmul = mul(Z1, Z2);
    Z1.afficher(); cout << endl; Z2.afficher(); cout << endl;
    cout << "z[somme] = "; Zsum.afficher();
    
    cout << "z[produit] = "; Zmul.afficher();
    
    cout << "|z1| = " << Z1.module() << endl; 
    
    return 0;
}

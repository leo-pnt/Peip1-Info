#include <iostream>
#include <math.h>
using namespace std;

double arithmetique(double &u0_f, double &r_f, double &n_f)
{
    double un_f_a = u0_f + n_f * r_f; //n-ieme terme de la suite arithmetique
    return un_f_a;
}

double geometrique(double &u0_g_f, double &r_g_f, double &n_g_f)
{
    double un_f_g = u0_g_f * pow(r_g_f,n_g_f);
    return un_f_g;
}




int main()
{
    char choix = ' ';
    cout << "suite arithmetique [a]\nsuite geometrique  [g]\n";
    cout << "votre choix ? >> "; cin >> choix;
    
    double u0(0);
    double r(0);
    double n(0);
    
    //trois cas : a, g ou autre
    if(choix == 'a')
    {
        cout << "u0 ? >> "; cin >> u0;
        cout << "r ? >> "; cin >> r;
        cout << "n ? >> "; cin >> n;
        cout << endl << "u(" << n << ") = " << arithmetique(u0,r,n) << endl;
    }
    
    else if(choix == 'g')
    {
        cout << "u0 ? >> "; cin >> u0;
        cout << "r ? >> "; cin >> r;
        cout << "n ? >> "; cin >> n;
        cout << endl << "u(" << n << ") = " << geometrique(u0,r,n) << endl;
    }
    
    else cout << "choix impossible !" << endl;
    
    
    
    
    return 0;
}

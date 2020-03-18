#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void racine(vector<double> &rac, double const& x_inf_r, double const& x_sup_r)
{
    double epsilon = 1e-13; //precision, cad,  0 + ou - epsilon, cf plus loin
    double PAS = 0.1;
    double N = (x_sup_r - x_inf_r)/PAS; //nb de valeurs entre borne inf et sup
    
    
    vector<double> x(N); //valeurs d'abscisse
    x[0] = x_inf_r; //on calcule toutes les valeurs d'abscisses de x_inf a x_sup
    for(double i=0; i<N; i++) x[i+1] = x[i] + PAS ; //le pas est de 0.1
    
    double Px; //polynome en fonction de x
    for(double i=0; i<N; i++)
    {
        //on calcule P
        Px = (x[i]+4)*(x[i]+2)*(x[i]+1)*(x[i]-1)*(x[i]-3)/20;
        
        //on ajoute la racine si P[i] tres proche de 0
        if(Px < epsilon && Px > -epsilon) rac.push_back(x[i]); //ac precision
    }
}

int main()
{
    double x_inf = -5;
    double x_sup = 4;
    
    vector<double> R;// racines
    
    racine(R, x_inf, x_sup);
    
    for(unsigned i = 0; i < R.size(); i++)
    {
        if(R[i] < 0) cout << "r("<<i<<") = " << R[i] << endl;
        else cout << "r("<<i<<") =  " << R[i] << endl;
    }
    return 0;
}

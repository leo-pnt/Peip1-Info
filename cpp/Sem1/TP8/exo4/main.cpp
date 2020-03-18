#include <iostream>
#include <math.h>
#include <stdlib.h> //pour valeur absolue
using namespace std;

double f(double x_f) {return 4 * sqrt(1 - pow(x_f, 2));}


//methode des trapeze
double integrale_trap(double const& b_inf_trap, double const& b_sup_trap, int const& nb_val_trap)
{
    double Aire_trap = 0; //c'est l'integrale, ou somme de toutes les aires rectangles
    
    //plus petite unite en abscisse
    double inter_trap = (b_sup_trap - b_inf_trap) / (nb_val_trap + 1);
    for(double i = b_inf_trap; i <= b_sup_trap - inter_trap; i += inter_trap)
    {
        Aire_trap += (f(i+inter_trap)+f(i))/2;
    }
    
    return inter_trap * Aire_trap;
}


//meth des rectangles
double integrale_rect(double const& b_inf, double const& b_sup, int const& nb_val)
{
    double Aire = 0; //c'est l'integrale, ou somme de toutes les aires rectangles
    
    //plus petite unite en abscisse
    double inter = (b_sup - b_inf) / (nb_val + 1);
    for(double i = b_inf; i < b_sup; i += inter)
    {
        Aire += f(i);
    }
    
    return inter * Aire;
}

int main()
{
    double borne_inf = 0, borne_sup = 1;
    
    int nb_valeur;
    cout << "nb_valeur? "; cin >> nb_valeur;
    cout << endl;
    cout << "l'integrale vaut (Rn) " << integrale_rect(borne_inf, borne_sup, nb_valeur);
    cout << endl;
    cout << "l'integrale vaut (Tn) " << integrale_trap(borne_inf, borne_sup, nb_valeur);
    cout << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

//methode des rectangle carre
double integrale(double const& b_inf, double const& b_sup, int const& nb_val)
{
    double Aire = 0; //c'est l'integrale, ou somme de toutes les aires rectangles
    
    //plus petite unite en abscisse
    double inter = (b_sup - b_inf) / (nb_val + 1);
    for(double i = b_inf; i < b_sup; i += inter)
    {
        if(i != 0) Aire += 1/i;
    }
    
    return inter * Aire;
}

int main()
{
    double borne_inf, borne_sup;
    cout << "borne_inf? "; cin >> borne_inf;
    cout << "borne_sup? "; cin >> borne_sup;
    
    int nb_valeur;
    cout << "nb_valeur? "; cin >> nb_valeur;
    cout << endl;
    cout << "l'integrale vaut " << integrale(borne_inf, borne_sup, nb_valeur);
    cout << endl;
    
    return 0;
}

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;



int main()
{
    double pi = 3.14159265358979323846;
    double N(30);
    do{
    cout << "N (maximum 25) ? "; cin >> N;
    }
    while (N > 25 || N < 1);
    
    double Dx = 2 * pi / (N - 1); //delta x
    vector<double> x(25); //toutes les valeurs de x;
    for(double i = 0; i < N - 1; i++)
    {
        x[i] = i * Dx;
    }
    
    vector<double> f(25); //fonction f
    
    // on stock les valeurs de f dans le tableau
    for(double i = 0; i < N - 1; i++)
    {
        f[i] = sin(x[i]);
    }
    
    vector<double> dfDA(25); //df Difference Avant
    
    // on stock les valeurs de df DA dans le tableau
    for(double i = 0; i < N - 1; i++)
    {
        dfDA[i] = (f[i+1] - f[i])/Dx;
    }
    
    vector<double> dfDC(25);//df Difference Centrale
    
    // on stock les valeurs de df DC dans le tableau
    for(double i = 1; i < N - 1; i++)
    {
        dfDC[i] = (f[i+1] - f[i-1])/(2*Dx);
    }
    
    vector<double> dfDE(25);//df analytique -> cosinus
    // on stock dans dfDE le cosinus (derivee analytique de sinus)
    for(double i = 0; i < N - 1; i++)
    {
        dfDE[i] = cos(x[i]);
    }
    
    //affichage
    for(double i = 0; i < N; i++)
    {
        cout<< f[i] <<"  "<< dfDA[i] <<"  "<< dfDC[i] <<"  "<< dfDE[i] <<endl;
    }
    
    return 0;
}

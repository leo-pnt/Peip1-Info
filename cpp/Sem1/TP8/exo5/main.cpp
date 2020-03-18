#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

double random_0_1() //nombre aleatoire en 0 et 1
{
    return (float)rand() / (float)RAND_MAX;
}

int main()
{
    srand((unsigned)time(NULL));//synchro prog avec horloge interne
    
    double N(0); //nombre de points entre 0 et 1
    cout << "N? "; cin >> N;
    double point_y(0); //point y compris de 0 a 1
    double semi_x(0); //semi_x compris de 0 a 1, semi_x de PAS 1/(N+1)
    double C(0); //compteur, +1 chaque fois que distance inferieur a 1
    
    for(semi_x = 0; semi_x <= 1; semi_x += 1/(N+1))
    {
        point_y = random_0_1();
        if (sqrt(pow(semi_x, 2) + pow(point_y, 2)) < 1) C += 1;
    }
    
    double pi = 4*C/N;
    cout << "pi = " << pi << endl;
    
    return 0;
}

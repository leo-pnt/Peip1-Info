#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


double frand_a_b(double a, double b) //fonction aleatoire entre a et b
{
    return (rand()/(double)RAND_MAX ) * (b-a) + a;
}

void tab_neg(vector<double> &pTabf, vector<double> &pTab_negative, int const& len)
{
    for(int i = 0; i < len; i++)
    {
        //on ajoute la valeur si elle est negative
        if(pTabf[i] < 0) pTab_negative.push_back(pTabf[i]);
    }
}

int main()
{
    int N;
    
    
    srand(time(NULL)); //synchro pour rand()
    cout << "N ? "; cin >> N;
    
    vector<double> pTab(N); //creation pointeur tableau
    
    
    //creation tableau de longueur N genere aleatoirement
    for(int i = 0; i < N; i++)
    {
        pTab[i] = frand_a_b(-10,10);
    }
    
    //affiche pTab
    cout << "pTab : " << endl;
    for(int i = 0; i < N; i++)
    {
        cout << pTab[i] << endl;
    }
    cout << endl;
    
    vector<double> pTab_neg; //tableau vide auquel on ajoutera les val negatives
    
    // on execute la fonction qui "supprime les valeurs positives"
    tab_neg(pTab, pTab_neg, N);
    
    
    for (int i =0; i< pTab_neg.size(); i++)
    {
        cout << pTab_neg[i] << endl;
    }
    
    cout << endl;
    return 0;
}

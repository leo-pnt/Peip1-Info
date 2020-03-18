#include <iostream>
using namespace std;



bool nbPremier(int nbr)
{
    int divisable = 0; //nombre de fois que la division donne un reste nul. cf plus loin

    for(int i=1; i<=nbr; i+=1)
    {
        if(nbr%i == 0) divisable +=1;
    }
    if (divisable == 2) return true; //car divisable par 1 et par lui meme
    else return false;
}



int main()
{
    int nb;

    cout << "[Nombre Premier]" << endl << endl;

    do
    {
        cout << "Nombre? "; cin >> nb;


        if (nbPremier(nb) == true) cout << "OUI,      -1 pour quitter" << endl << endl;
        else cout << "NON,      -1 pour quitter" << endl << endl;
    }
    while(nb != -1);

    
    return 0;
}

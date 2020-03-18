#include <iostream>
using namespace std;
#include <string.h>
#include <fstream>
#include "CIndividu.h"
#include "CEleve.h"
#include "CPromo.h"



int main()
{
    //pour l'écriture :
    //CPromo promo(2);
    //cin >> promo;
    //promo.ecriture("promo.txt");

    //pour la lecture :
    CPromo promoBis;
    promoBis.lecture("promo.txt");
    cout << promoBis << endl;

	cin.get();cin.get();
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int x, y;
	int choix;
	int choix2=1;
	bool recommencer;

	do{
	cout << "x? "; cin >> x; cout << "y? "; cin >> y;
	cout << "addition -> 1 \nsoustraction -> 2 \nmultiplication -> 3 \ndivision -> 4" << endl;
	cout << "votre choix? "; cin >> choix;

	switch (choix)
	{
	case 1: cout << "x+y = " << x + y; break;
	case 2: cout << "x-y = " << x - y; break;
	case 3: cout << "x*y = " << x * y; break;
	case 4: cout << "x/y = " << x / y; break; // le resultat est un entier
	default: cout << "choix impossible" << endl;
	}

	cout << "recommencer ? (1)OUI (2)NON "; cin >> choix2;
	if(choix2 == 1) recommencer = true;
	else recommencer = false;

	}while(recommencer==true);


    return 0;
}

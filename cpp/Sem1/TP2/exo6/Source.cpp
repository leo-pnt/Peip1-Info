#include <iostream>
using namespace std;

void main()
{
	int x, y;
	int choix;
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

}
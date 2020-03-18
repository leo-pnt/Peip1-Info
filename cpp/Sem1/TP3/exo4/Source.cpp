#include <iostream>
using namespace std;

void main()
{
	int val;
	int somme = 0;
	int moy;
	int n=0;

	do
	{
		cout << "val? ";
		cin >> val;

		somme += val;
		n += 1;
	} while (val != -1);

	moy = somme / n;

	cout << "Sommme = " << somme;
	cout << "Moyenne = " << moy;
}
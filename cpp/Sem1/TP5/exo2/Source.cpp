#include <iostream>
using namespace std;

int arrondi(double const& nb)
{
	int entier = (int)nb;
	double decimale = nb - entier;

	if (decimale >= 0.5) return ((int)nb + 1);
	else return (int)nb;
}

int main()
{
	double nombre;

	do
	{
		cout << "nombre ?";
		cin >> nombre;
		cout << "arrondi = " << arrondi(nombre) << endl;
	} while (nombre != -1);

	return 0;
}

#include <iostream>
using namespace std;

void main()
{
	int longueur;
	int largeur;
	int surface;
	cout << "longueur? ";
	cin >> longueur;
	cout << "largeur? ";
	cin >> largeur;

	surface = longueur * largeur;
	cout << "Surface = " << surface << " metre carre"<< endl;
}
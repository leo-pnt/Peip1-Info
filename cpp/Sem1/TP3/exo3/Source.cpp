#include <iostream>
using namespace std;

int main()
{
	int i;
	int n;
	int val;
	int somme = 0;
	int moy;

	cout << "cb de valeurs a saisir ?";
	cin >> n;

	for (i = 1; i <= n; i += 1)
	{
		cout << "valeur? ";
		cin >> val;
		somme += val;
	};
	moy = somme / n;
	cout << "Somme = " << somme<< endl;
	cout << "Moyenne = " << moy << endl;

	return 0;
}
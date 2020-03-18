#include <iostream>
using namespace std;

bool entier_ou_pas(int nb)
{
	int i;
	int nb_de_diviseurs = 0;
	int premier_diviseur;

	for (i = 1; i <= nb; i += 1)
	{
		if (nb%i == 0)
		{
			if (i != 1) premier_diviseur = i;
			nb_de_diviseurs += 1;
		}
	};

	if (nb_de_diviseurs == 2)
	{
		return premier_diviseur;
		return true;
	}
	else
	{
		return 1;
		return false;
	}
}

int main()
{
	int nb_entier;

	do
	{
		cout << "Nombre entier ? ";
		cin >> nb_entier;

		if (entier_ou_pas(nb_entier) == true)
		{
			cout << "True, premier_diviseur = " << endl;
		}
		else cout << "False" << endl;
	}while (nb_entier != -1);

	return 0;
}
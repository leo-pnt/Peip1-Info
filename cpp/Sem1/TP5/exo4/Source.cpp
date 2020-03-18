#include <iostream>
using namespace std;

bool entier_ou_pas(int nb, int & premier_diviseur_ref)
{
	int i;
	int nb_de_diviseurs = 0;
	int compteur = 0; //pour ne retenir qu'une seule valeur de premier_diviseur_ref dans la boucle

	for (i = 1; i <= nb; i += 1)
	{
		if (nb%i == 0)
		{
			if (compteur < 2) premier_diviseur_ref = i;
			nb_de_diviseurs += 1;
			compteur += 1;
		}
	};

	if (nb_de_diviseurs == 2)
	{
		return true;
	}
	else
	{
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
		int premier_diviseur;

		if (entier_ou_pas(nb_entier, premier_diviseur) == true)
		{
			cout << "True, premier_diviseur = " << premier_diviseur << endl;
		}
		else cout << "False, premier_diviseur = " << premier_diviseur << endl;
	} while (nb_entier != -1);

	return 0;
}
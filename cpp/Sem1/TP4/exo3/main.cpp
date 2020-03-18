#include <iostream>
using namespace std;

int main()
{
	int i;
	int val;
	int valR;
	int tab[10];

	for (i = 0; i < 10; i+=1) //demande les 10 valeurs du tableau 'tab'
	{
		cout << "valeur " << i + 1 << "? ";
        cin >> val;
        tab[i]=val;
	}

	do{
	cout << "valeur recherchee ? "; cin >> valR;

	for (i=0; i<10; i+=1)
	{
		if(tab[i] == valR)
        {
            cout << "valeur trouvee a la ligne " << i + 1 << endl;
        };
	}

	}while(valR != -1);


	return 0;
}

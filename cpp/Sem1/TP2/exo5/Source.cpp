#include <iostream>
using namespace std;

void main()
{
	char lettre;
	char a;
	char e;
	char i;
	char o;
	char u;

	a = 'a';
	e = 'e';
	i = 'i';
	o = 'o';
	u = 'u';

	cout << "lettre? "; cin >> lettre;
	if (lettre == a)
	{
		cout << "voyelle" << endl;
		cout << "avion";
	}
	else if (lettre == o) 
	{
		cout << "voyelle" << endl;
		cout << "oiseau";
	}
	else if (lettre == u)
	{
		cout << "voyelle" << endl;
		cout << "utile";
	}
	else if (lettre == e)
	{
		cout << "voyelle" << endl;
		cout << "euro";
	}
	else if (lettre == i)
	{
		cout << "voyelle" << endl;
		cout << "indice";
	}
	else cout << "consone";

}
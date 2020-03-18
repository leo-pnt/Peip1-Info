#include <iostream>
using namespace std;

void main()
{
	int moyenne;
	cout << "moyenne? "; cin >> moyenne;
	
	if (moyenne >= 10 && moyenne < 12) cout << "mention PASSABLE";
	else if (moyenne >= 12 && moyenne < 14) cout << "mention ASSEZ BIEN";
	else if (moyenne >= 14 && moyenne < 16) cout << "mention BIEN";
	else cout << "sans reponse";
}
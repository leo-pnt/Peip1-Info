#include <iostream>
using namespace std;

float swap(float val1, float & val2)
{
	val2 = val1;
	return val1;
}

int main()
{
	float valA;
	float valB;

	cout << "Entrez deux valeurs : "; cin >> valA; cin >> valB;
	cout << "vos valeurs " << valA << " " << valB << endl;
	cout << "apres swap " << swap(valA, valB) << " " << valB << endl;

	cin.get(); cin.get();

	return 0;
}
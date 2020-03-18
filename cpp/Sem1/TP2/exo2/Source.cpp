#include <iostream>
using namespace std;

void main()
{
	int x;
	cout << "x? "; cin >> x;
	
	if (x < 0) cout << "x strict negatif";
	else if (x > 0) cout << "x strictement positif";
	else cout << "x positif";
	
}
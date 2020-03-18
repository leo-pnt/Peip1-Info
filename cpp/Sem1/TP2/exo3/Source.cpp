#include <iostream>
using namespace std;

void main()
{
	int a, b, c, d;

	cout << "a? "; cin >> a;
	cout << "b? "; cin >> b;
	cout << "c? "; cin >> c;
	cout << "d? "; cin >> d;

	if (a <= b && b <= c && c <= d) cout << "ordre croissant";
	else cout << "desordonne";
}
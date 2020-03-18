#include <math.h>
#include <iostream>
using namespace std;

void main()
{
	int a, x;
	cout << "a? ";
	cin >> a;
	cout << "x? ";
	cin >> x;
	cout << "p(a,x)= " << exp(x) + a << endl;
}
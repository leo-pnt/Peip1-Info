#include <iostream>
using namespace std;

int main()
{
	int n;
	int i;
	cout << "n?"; cin >> n;
	double factorielle;
	factorielle = 1;
	for (i = 1; i <= n; i += 1)
	{
		factorielle *= i;
	};
	cout << "factorielle= " << factorielle << endl;

	return 0;
}

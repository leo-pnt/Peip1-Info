#include <iostream>
using namespace std;

void main()
{
	int i;
	for (i = 1; i <= 5; i += 1) //affiche 5 tirages aleatoires
	{
		int tiragei = rand();
		cout << "tirage" << i << " = " << tiragei << endl;
	};
}
#include <iostream>
using namespace std;

void main()
{
	int a, b;
	int reste;

	cout << "a? "; cin >> a;
	cout << "b? "; cin >> b;

	reste = a % b;
	if (reste == 0) cout << " b divise a de façon entière";
	else cout << "b ne divise pas a de façon entière";
}
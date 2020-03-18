#include <iostream>
using namespace std;

double celsius(double TK) //fonction kelvin vers celsius
{
	return(TK - 273.15);
}

double fahrenheit(double TC) //fonction celsius vers fahrenheit
{
	return((9 / 5)*TC + 32);
}


int main()
{
	double temp;
	cout << "temperature en kelvin? ";
	cin >> temp;
	cout << "T = " << celsius(temp) << " degre Celsius" << endl;
	cout << "T = " << fahrenheit(celsius(temp)) << " degre Fahrenheit";

	return 0;
}
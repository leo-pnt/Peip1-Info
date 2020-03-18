#include <iostream>
using namespace std;

double calculerFactorielle(double const& n)
{
    double factorielle(1);
    for(int i = 1; i <= n; i++)
    {
        factorielle *= i;
    }
    return factorielle;
}

int main()
{
    double N;
    cout << "factorielle jusqu'à ? ";
    cin >> N;
    
    cout << "n! = " << calculerFactorielle(N) << endl;
    
    return 0;
}

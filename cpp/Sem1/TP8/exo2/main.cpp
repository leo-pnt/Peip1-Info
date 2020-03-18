#include <iostream>
#include <math.h>
using namespace std;

double leibniz(int &N)
{
    double pi(0);
    //on fait la somme de 0 a n
    for(int i = 0; i <= N; i++)
    {
        pi += pow(-1,i)/(2*i + 1);
    }
    return 4*pi;
}

int main()
{
    cout << "[pi selon Leibniz]\n" << endl;
    
    int n(0);
    cout << "n? "; cin >> n;
    cout << endl << "pi vaut environ " << leibniz(n);
    cout << endl;
    
    
    return 0;
}

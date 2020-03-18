#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    double a, b, c;
    
    cout << "ax^2 + bx + c = 0" << endl << endl;
    cout << "a? "; cin >> a;
    cout << "b? "; cin >> b;
    cout << "c? "; cin >> c;
    
    double delta = pow(b,2) - 4*a*c;
    
    
    
    if(delta == 0) cout << "x0 = " << -b/(2*a) << endl;
    
    else if(delta > 0)
    {
        cout << "x1 = " << (-b-sqrt(delta))/(2*a) << endl;
        cout << "x2 = " << (-b+sqrt(delta))/(2*a) << endl;
    }
    
    else
    {
        double re = (-b/(2*a));
        double im = sqrt(-delta)/(2*a);
        
        cout << "x1 = " << re << " + " << im << "i" << endl;
        cout << "x2 = " << re << " - " << im << "i" << endl;
    }
    
    
    return 0;
}

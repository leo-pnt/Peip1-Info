#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a; a=b; b=temp;
}

int main()
{
    int x, y;
    
    cout << "x? "; cin >> x;
    cout << "y? "; cin >> y;
    
    cout << "x.av = " << x << endl;
    cout << "y.av = " << y << endl;
    
    swap(x,y);
    
    cout << "x.ap = " << x << endl;
    cout << "y.ap = " << y << endl;
    
    return 0;
}

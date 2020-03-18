#include <iostream>
using namespace std;


int pgcd(int a, int b)
{
    int r; //reste de la div de a par b
    
    if(a==0 || b==0) return -1;
    else if(a <= b)
    {
        int a_memory = a;
        a=b;
        b=a_memory;
    }
    
    do
    {
        r = a%b;
        a=b;
        if(r != 0) b=r;
    }while (r != 0);
    
    return b;
}

int main()
{
    int x, y;
    
    cout << "PGCD" << endl;
    cout << "x? "; cin >> x;
    cout << "y? "; cin >> y;
    
    cout << "PGCD = " << pgcd(x,y) << endl;
    
    return 0;
}

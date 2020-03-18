#include <iostream>
#include <complex>
using namespace std;


complex<int> addition(complex<int> &za1, complex<int> &za2)
{
    return za1 + za2;
}

complex<int> soustraction(complex<int> &zs1, complex<int> &zs2)
{
    return zs1 - zs2;
}

complex<int> multiplication(complex<int> &zm1, complex<int> &zm2)
{
    return zm1 * zm2;
}


int main()
{
    int re1, re2, im1, im2; //reelle, imaginaire
    complex<int> z;
    
    cout << "Soit z1 = re1 + i im1" << endl;
    cout << "re1 ? "; cin >> re1;
    cout << "im1 ? "; cin >> im1; cout << endl;
    
    complex<int> z1(re1, im1);
    
    cout << "Soit z2 = re2 + i im2" << endl;
    cout << "re2 ? "; cin >> re2;
    cout << "im2 ? "; cin >> im2; cout << endl;
    
    complex<int> z2(re2, im2);
    
    cout <<"[1] z1 + z2\n[2] z1 - z2\n[3] z1 x z2\n";
    int choix;
    cout << "votre choix ? "; cin >> choix;
    
    
    switch(choix)
    {
        case 1 : cout << "z = " << addition(z1, z2) << endl;
            break;
        case 2 : cout << "z = " << soustraction(z1, z2) << endl;
            break;
        case 3 : cout << "z = " << multiplication(z1, z2) << endl;
            break;
            
        default : cout << "choix impossible" << endl;
            break;
    }
    
    return 0;
}

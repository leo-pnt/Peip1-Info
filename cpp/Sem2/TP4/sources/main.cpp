#include <iostream>
using namespace std;

#include "CTab2D.h"

int main()
{
    int L = 4;
    int C = 6;

    CTab2D tab(L,C,0);
    tab.fillRand();
    cout << tab << endl;

    cout << "tab(3,2): " << tab(3,2) << endl;
    
    cout << "ligne[" << L-1 << "]: ";
    for(int j = 0; j < C; j++)
        cout << tab[L-1][j] << "  ";
    cout << endl;

    cin.get();
    return 0;
}
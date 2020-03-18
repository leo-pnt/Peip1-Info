#include <iostream>
using namespace std;

int main()
{
    int tab[5];
    
    for(int i = 0; i < 5; i++) //on entre les valeurs dans tab
    {
        cout << "tab[i] ? ";
        cin >> tab[i];
    }
    
    for (int i = 0; i < 5; i++)
    {
        //swap les valeurs (par couple de deux) si decroissant
        //cad decale la plus grande valeur a droite du tableau et ainsi de suite
        for (int n = 0; n < 4; n++)
        {
            if (tab[n+1] < tab[n]) swap(tab[n+1], tab[n]);
        }
    }
    cout << "tab : "; for(int i = 0; i < 5; i++) cout << "|" << tab[i];
    cout << "|" << endl;
    
    return 0;
}

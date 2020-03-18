#include <iostream>
using namespace std;

int minmax(int ptr[], int len, int &min) //ne pas oublier les crochets du pointeur
{
    int max = ptr[0];
    min = ptr[0];
    
    for(int i = 0; i < len - 1; i++)
    {
        if(ptr[i+1] >= ptr[i] && max <= ptr[i+1]) max = ptr[i+1]; //stock la valeur de max
        else if(ptr[i+1] <= ptr[i] && min >= ptr[i+1]) min = ptr[i+1]; //stock la valeur de min
    }
    return max;
}

int main()
{
    int minimum(0); //apres passage par ref de "min"
    int tab_len;
    int *ptab(0); //definie le pointeur sans pointage (temporairement)
    
    cout << "longueur du tableau ? "; cin >> tab_len;
    
    
    //on demande une ref memoire sans valeur que l'on associe au pointeur
    ptab = new int[tab_len];
    
    //remplissage tu tableau
    for(int i = 0; i < tab_len; i++)
    {
        cout << "ptab[" << i << "] ? "; cin >> ptab[i];
    }
    
    
    cout << endl;
    cout << "max = " << minmax(ptab, tab_len, minimum) << " | min = " << minimum;
    
    
    cout << endl;
    delete[] ptab; //desallocation memoire, ne pas oublier les crochets qd pTableau
    ptab = 0; //depointage
    
    return 0;
}

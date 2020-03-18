#include <iostream>
using namespace std;

int main()
{
    int val = 4;
    int *p_val(0); //
    p_val = &val; //p_val pointe sur la reference de val
    cout << &val << endl; //affiche ref memoire de val
    cout << val << endl; //affiche la valeur inscrit dans cette case memoire
    cout << *p_val << endl; //affiche la valeur de la case memoire val, p_val pointant vers celle-ci
    cout << p_val << endl; //affiche le pointeur en question
    cout << &p_val << endl; //affiche la reference du pointeur
    
    delete p_val;
    p_val = 0;
    
    return(1);
}

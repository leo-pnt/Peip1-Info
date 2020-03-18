#include <iostream>
#include <vector>
using namespace std;


int main()
{
    cout << "[Syracuse]\n" << endl;
    
    int u0, n;
    
    cout << "n ? "; cin >> n;
    cout << "u0 ? "; cin >> u0;
    
    vector<int> suite_pair(1); //taille initiale 1 case, c'est important
    suite_pair[0] = (int)u0;//premier terme de la suite, conversion en double
    
    //on calcule la suite jusqu'a u(n) dans le cas pair
    for(int i = 0; i < n; i++)
    {
        suite_pair.push_back(suite_pair[i]/2);
    }
    /*cout << "test ";
    for(int i =0; i < suite_pair.size(); i++)
    {
        cout << suite_pair[i] << " " << endl;
    }*/
    
    vector<int> suite_impair(1);
    suite_impair[0] = u0;//premier terme de la suite
    
    //on calcule la suite jusqu'a u(n) dans le cas impair
    for(int i = 0; i < n; i++)
    {
        suite_impair.push_back(3*suite_impair[i]+1);
    }
    
    if(suite_pair[n]%2 == 0)
    {
        cout << "u(n) = " << suite_pair[n] << endl;
    }
    else cout << "u(n) = " << suite_impair[n] << endl;
    
    return 0;
}

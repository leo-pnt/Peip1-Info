#include <iostream>

using namespace std;

int main()
{
    int i;
    char tab[27];
    char mot;
    char lettrei;
    cout << "mot ?"; cin >> mot;
    cout << "epeler mot :";

    for (i=0;i<=sizeof(mot);i++)
    {
        cin >> lettrei;
        tab[i]=lettrei;
    };

    for (i=0;i<=sizeof(mot);i++) cout<< tab[i];


    return 0;
}

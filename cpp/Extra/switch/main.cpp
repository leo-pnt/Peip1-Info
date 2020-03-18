#include <iostream>
using namespace std;

int main()
{
    int choix;
    
    cout << "Menu :\n(1)\n(2)\n(3)" << endl;
    
    cin >> choix;
    
    switch(choix)
    {
        case 1 : cout << "1." << endl;
        break;
        
        case 2 : cout << "2." << endl;
        break;
        
        case 3 : cout << "3." << endl;
        break;
        
        default : cout << "Choix impossible" << endl;
    }
    
    return 0;
}

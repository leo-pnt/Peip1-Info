#include <iostream>
using namespace std;


int main()
{
    int i;
    char batons[20];
    for(i=0;i<20; i+=1)
    {
        batons[i]='|';
    }
    cout << batons;
    int choix;
    int tour = 20;
    int bin; //1 ou 2 selon le joueur;
    
    cout << endl<<"Jeu des batons [-1 pour quitter]" << endl;
    cout << "Joueur 1 commence : "; cin >> choix;
    
            if(choix == 3)
            {
                batons[tour] = ' ';
                batons[tour-1] = ' ';
                batons[tour-2] = ' ';
                tour -= choix;
            }
            else if(choix == 2)
            {
                batons[tour] = ' ';
                batons[tour-1] = ' ';
                tour -= choix;
            }
            else if(choix == 1)
            {
                batons[tour] = ' ';
                tour -= choix;
            }
            
    if(choix!= -1)cout << batons << endl;
    
    bin = 2;
    
    if (choix != -1)
    {    
    do
    {
        
        cout << "[Joueur" << bin << "]>> ";
        cin >> choix;
        if(tour >= 3)
        {
            if(choix == 3)
            {
                batons[tour] = ' ';
                batons[tour-1] = ' ';
                batons[tour-2] = ' ';
                tour -= choix;
            }
            else if(choix == 2)
            {
                batons[tour] = ' ';
                batons[tour-1] = ' ';
                tour -= choix;
            }
            else if(choix == 1)
            {
                batons[tour] = ' ';
                tour -= choix;
            }
            cout << batons << endl;
        }
        else if(tour < 3)
        {
            if(choix == 3)
            {
                batons[tour] = ' ';
                batons[tour-1] = ' ';
                choix = 2;
            }
            else if(choix == 2)
            {
                batons[tour] = ' ';
                batons[tour-1] = ' ';
            }
            else if(choix == 1)
            {
                batons[tour] = ' ';
            }
            tour -= choix;
            cout << batons << endl;
        }
        if(bin == 2) bin = 1;
        else bin = 2;
        
        
    }while (tour >0 && choix !=-1);
    };
    
    if(bin == 2) bin = 1;
    else bin = 2;
    
    if(choix != -1) cout << "joueur " << bin << " a gagné !" << endl;
    else cout << "joueur " << bin << " a mis fin a la partie" << endl;
    
    return 0;
}

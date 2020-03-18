#include <iostream>
using namespace std;

int main()
{
    int lignes; //nb de lignes du triangle
    int isolignes; //2*lignes car on enleve les cas où i est pair, cf plus loin
    int choix; //rectangle ou isocele
    int i; //nb lignes
    int j; //nb etoiles par lignes
    int n; //nb espaces av etoiles
    int k = 0; //resout pb d'espace avant etoiles pour triangle isocele
    char eto='*'; // etoile


    cout<<"rectangle (1)\nisocele   (2)"<<endl << endl; // \n -> retour à la ligne
    cout<<"Choix? "; cin>>choix;

    if (choix == 1) //cas du triangle rectangle
    {
        cout << "nb de lignes du triangles? ";
        cin >> lignes; cout << endl;

        for(i=1; i<=lignes; i+=1) //fait i retour à la ligne
        {
            for(j=1; j<=i; j+=1) //fait j étoiles par ligne
            {
                cout << "*";
            };
            cout << endl;
        };
    }
    else if (choix == 2) // cas du triangle isocele...
    {
        cout << "nb de lignes du triangles? ";
        cin >> lignes; cout << endl;
        isolignes=2*lignes; // car on enleve les cas où i est pair, en effet chaque lignes comporte un nb impair d'etoile

        for(i=1; i<=isolignes; i+=1) //fait un retour a la ligne à chaque fois que i est impair (*)
        {
            if(i%2!=0) // verifie que i est impair
            {
                k+=1; //on ne peut pas utiliser i car isolignes est trop grand et est constant
                for(n=1; n<=lignes-k; n+=1) //fait le bon nombre d'espace par ligne
                {
                    cout <<" ";
                };
            }

            if (i%2!=0) //verifie que i est impair
            {
                for (j=1; j<=i; j+=1) //affiche le bon nb d'etoile par ligne
                cout << eto;
            }
            if (i%2!=0) cout << endl; //verifie i impair (*)
        };
    }
    else cout << "choix impossible"; //si choix != 1 ou 2

    return 0;
}

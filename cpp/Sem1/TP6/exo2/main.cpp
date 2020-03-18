#include <vector>
#include <iostream>
using namespace std;

void swap(int &a, int &b) //echange a et b
{
    int memory = a; a=b; b=memory;
}


//trie_croissant :
//on met "&" devant tab pour ne pas copier tout le tableau de main()
//dans une nouvelle variable et ainsi optimiser le programme
//pareille pour longueur avec "const" en plus pour ne pas "autoriser" la fonction a la
//modifier
void trie_croissant(vector<int> & tab, int const& longueur)
{
    for (int i = 0; i < longueur; i++)
    {
        //swap les valeurs (par couple de deux) si decroissant
        //cad decale la plus grande valeur tout a droite du tableau
        for (int n = 0; n < longueur - 1; n++)
        {
            if (tab[n+1] < tab[n]) swap(tab[n+1], tab[n]);
        }
    }//on reitere pour decaler la deuxieme plus grande valeur juste devant LA plus grande et ainsi de suite
}



int main()
{
    int len; //longueur du tableau
    
    cout << "combien de valeurs entieres ?\n(nb impair uniquement) "; cin >> len;
    if(len%2 == 0) {cout << "nb impair uniquement !" << endl; return 0;}
    
    
    vector<int> pTab(len); //creation de pTab de longeur len
    
    //saisie des valeurs dans pTab
    for(int i=0; i< len; i++)
    {
        cout << "pTab[" << i << "] ? ";
        cin >> pTab[i];
    }
    cout << endl;
    
    //affiche pTab
    cout << "pTab :";
    for(int i=0; i< len; i++)
    {
        cout << " " << pTab[i];
    }
    cout << endl << endl;
    
    
    // effectue le trie_croissant
    trie_croissant(pTab, len);
    
    
    //affiche pTab trie
    cout << "pTab_trie :";
    for(int i=0; i< len; i++)
    {
        cout << " " << pTab[i];
    }
    cout << endl;
    
    int mediane = pTab[(len+1)/2 - 1];
    cout << "mediane = " << mediane << endl;
    
    return 0;
}


/*   fonctionne mais code très bof (sans <vector>)
int main()
{
    int nb_valeurs;
    
    cout << "combien de valeurs a saisir (nb impair obligatoire) ? "; cin >> nb_valeurs;
    
    //creation du tableau dynamique pTab
    int *pTab;
    pTab = new int[nb_valeurs];
    
    if(nb_valeurs%2 == 0) return 0;
    
    else
    {
        for (int i = 0; i < nb_valeurs; i++) //entre les valeurs dans pTab
        {
            cout << "pTab[" << i << "] ? "; cin >> pTab[i];
        }
    }
    cout << endl;
    
    //creation du tableau dynamique pTab_trie
    int *pTab_trie;
    pTab_trie = new int[nb_valeurs];
    
    for (int i = 0; i < nb_valeurs; i++) //soit pTab_trie = pTab pour tout i
    {
        pTab_trie[i] = pTab[i];
    }
    
    
    //range les valeurs par ordre croissant dans pTab_trie :
    for (int i = 0; i < nb_valeurs; i++)
    {
        //swap les valeurs (par couple de deux) si decroissant
        //cad decale la plus grande valeur a droite du tableau
        for (int n = 0; n < nb_valeurs - 1; n++)
        {
            if (pTab_trie[n+1] < pTab_trie[n]) swap(pTab_trie[n+1], pTab_trie[n]);
        }
    }//on reitere pour decaler la deuxieme plus grande valeur juste avant la plus grande et ainsi de suite
    cout << "pTab_trie : ";
    for(int i = 0; i<nb_valeurs; i++) cout << "|" << pTab_trie[i]; cout << "|" << endl;
    
    
    //calcul mediane
    int indice_mediane = nb_valeurs + 1;
    indice_mediane = indice_mediane/2;
    
    int mediane = pTab_trie[indice_mediane - 1]; //-1 pour l'indice du tableau
    
    
    delete[] pTab_trie; //desallocation
    
    cout << "pTab : ";
    for(int i = 0; i<nb_valeurs; i++) cout << "|" << pTab[i]; cout << "|" << endl;
    cout << "mediane : " << mediane << endl;
    
    delete[] pTab;
    pTab = 0;
    
    return 0;
}
*/

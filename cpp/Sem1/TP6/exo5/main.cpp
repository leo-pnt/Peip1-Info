#include <iostream>
#include <vector>
using namespace std;

void screen(vector<int> &batons_screen) //affiche les batons
{
    for(int i=0; i < batons_screen.size(); i++) cout << batons_screen[i];
    cout << endl;
}


//retire n batons
void remove_baton(vector<int> &batons_before, int &n)
{
    if(n==1) batons_before.pop_back();
    
    else if(n==2 && batons_before.size() != 2)
    {
        batons_before.pop_back();
        batons_before.pop_back();
    }
    
    else if(n==3 && batons_before.size() != 2)
    {
        batons_before.pop_back();
        batons_before.pop_back();
        batons_before.pop_back();
    }
    
    else cout << "choix impossible !" << endl;
}


//change le numero du joueur actif
void next_player(int &player_now)
{
    if (player_now == 1) player_now = 2;
    else player_now = 1;
}


int main()
{
    int player = 1;
    int nb_bat = 0;
    
    vector<int> batons;
    do {cout << "cb de batons (4 minimum)? "; cin >> nb_bat;} while(nb_bat < 4);
    
    
    //ajout des nb_bat nombre de batons
    for(int i = 0; i < nb_bat; i++) batons.push_back(1);
    
    screen(batons);
    
    int N = 0; //nb de batons a retirer, choisi par le joueur
    do
    {
        cout << "[joueur" << player << "]>> "; cin >> N;
        remove_baton(batons, N);
        screen(batons);
        next_player(player);
    }
    while(batons.size() > 1 && N != -1);
    
    //next_player a ete appele une derniere fois, on donne le gagnant
    if(player == 2) cout << "joueur 1 a gagne !" << endl;
    else cout << "joueur 2 a gagne !" << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

class Pyramide
{
public:
    Pyramide() : m_y(1) {}
    Pyramide(int y) : m_y(y+y-1), m_eto(1) {}
    //(y+y-1) arnaque pour avoir n lignes et non pas juste n etoiles à la fin
    ~Pyramide() {}
    void Afficher()
    {
        for(int ligne = 1; ligne <= m_y; ligne++)
        {
            if(ligne % 2 != 0) //affichage si nombre impair
            {
            //affiche les espaces par ligne
            m_esp = (m_y - ligne) / 2;
            for(int esp = 0; esp < m_esp; esp++)
            {
                cout << " ";
            }
            
            //affiche les etoiles par ligne
            for(int eto = 0; eto < m_eto; eto++)
            {
                cout << "_";
            }
            cout << endl;
            m_eto += 2;
            }
        }
    }
private:
    int m_esp; //nb d'espaces par lignes
    int m_eto; //nb d'etoile par lignes
    int m_y; //nb de lignes max
};

int main()
{
    Pyramide pyramide(20); //creation de l'objet pyramide
    pyramide.Afficher();
    return 0;
}

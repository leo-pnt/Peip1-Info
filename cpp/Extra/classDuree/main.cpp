#include "Duree.h"
#include <iostream>
using namespace std;

int main() {
    Duree duree1(0,1,54), duree2(0,4,50);
    cout << duree1 << endl;
    cout << duree2 << endl;
    if(duree1 != duree2) {
        cout << "les durees ne sont pas egales !" << endl;
    }
    if(duree1 < duree2) {
        cout << "d1 inferieur a d2" << endl;
    }
    return 0;
}
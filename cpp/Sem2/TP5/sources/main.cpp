#include <iostream>
using namespace std;

#include "CMatrice.h"

int main()
{
    CMatrice mat1;
    CMatrice mat2;

    cin >> mat1;
    cin >> mat2;

    cout << "mat1 * mat2: " << endl;
    cout << mat1 * mat2 << endl;

    cin.get(); cin.get();
    return 0;
}
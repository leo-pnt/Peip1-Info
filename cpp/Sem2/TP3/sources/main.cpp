#include <iostream>
using namespace std;
#include "CVect.h"

int main()
{
    CVect Vector3(3);
    CVect Vector3Bis;

    //Vector3.ecrit_bin("data.bin");
    cout << Vector3 << endl;

    Vector3Bis.lit_bin("data.bin");
    cout << Vector3Bis << endl;

    cin.get(); cin.get();
    return 0;
}
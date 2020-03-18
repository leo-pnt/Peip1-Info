#include <iostream>
#include "Frac.h"
using namespace std;

int main() {
    Frac a(1,3);
    Frac b(1,2);
    cout << a - b << endl;
    return 0;
}
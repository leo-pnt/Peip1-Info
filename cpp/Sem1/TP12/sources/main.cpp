#include <iostream>
using namespace std;
#include "CVect.h"
#include <bits/stdc++.h>

int main()
{
    clock_t start, end;
    start = clock();

    const int dim = 2; //dimension
    double* comp = new double[dim]; //composantes
    comp[0] = 2;
    comp[1] = 3;

    double* comp2 = new double[3]; //composantes
    comp2[0] = 4;
    comp2[1] = 1;
    comp2[2] = 2;

    CVect u(3, comp2);

    CVect v(dim, comp);
    cout << u << " " << v << endl;
    cout << u.somme(v) << endl;

    cout << u*v << endl; //les vect n'ont pas la meme dimmension

    u = v;
    cout << u << " " << v << endl;
    cout << u + v << endl;

    cout << u*v << endl;

    delete[] comp;
    delete[] comp2;

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Execution time : " << fixed << time_taken << setprecision(5); 
    cout << " sec " << endl;

    return 0;
}
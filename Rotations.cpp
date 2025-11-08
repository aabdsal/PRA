#include <iostream>
#include <vector>
 
using namespace std;


int binariSergg(vector <int> n, int ini, int fini){
    int medio = (ini + fini) / 2;

    if (ini > fini)
        return -1;
    else{
        if (n[medio] < n[ini]) return  1 + binariSergg(n,  medio + 1, fini);
        else if(n[medio] > n[fini]) return 1 + binariSergg(n, ini, medio - 1);
        else if(nreturn medio;
    }
}
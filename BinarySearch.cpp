#include <iostream>
#include <vector>

using namespace std;
// soles servix pa llistes ordenaes
int binariSergg(vector <int> n, int buscar, int ini, int fini){
    int medio = (ini + fini) / 2;

    if (ini > fini)
        return -1;
    else{
        if (n[medio] < buscar) return binariSergg(n, buscar, medio + 1, fini);
        else if(n[medio] > buscar) return binariSergg(n, buscar, ini, medio - 1);
        else return medio;
    }
}
int main(){
    vector <int> v = {2, 3, 5, 6, 7, 8, 9};
    
    int res = binariSergg(v, 7, 0, v.size() - 1);
    
    if(res > 0) cout << "Elemento encotrado en indice: " << res << endl;
    else cout << "Elemento no encontrado\n";

    return 0;
}
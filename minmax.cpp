#include <iostream>
#include <vector>

using namespace std;
// soles servix pa llistes ordenaes
int Min(vector <int> a, int ini, int fini, int x){

   if (ini > fini) return -1;
   int mid = (ini + fini)/2;
   
   
}
int Max(vector <int> n, int ini, int fini, int x){
   int medio = (ini + fini)/2;

   if (ini > fini) return -1;
   else{
        if (n[medio])
        {
            /* code */
        }
        
   }
}
int main(){
    vector <int> v = {2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9};
    
    int res = Min(v, 0, v.size() - 1, 0);
    int res = Max(v, 0, v.size() - 1, 0);
    
    if(res > 0) cout << "Elemento encotrado en indice: " << res << endl;
    else cout << "Elemento no encontrado\n";

    return 0;
}
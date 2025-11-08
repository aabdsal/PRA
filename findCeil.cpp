#include <iostream>
#include <vector>

using namespace std;
// soles servix pa llistes ordenaes
int findCeil(vector <int> n, int x, int ini, int fini){
    int medio = (ini + fini) / 2;

    if (ini > fini)
        return -1;
    
        if (x <= n[ini]) return n[ini];
        else if(x > n[n.size() - 1]) return -1;
        else if (x == n[medio]) return medio;
        else if(x > n[medio]) return findCeil(n, x, medio + 1, fini);
        else if(x < n[medio]) return findCeil(n, x, ini, medio - 1);
    
}
int findFloor(vector <int> n, int x, int ini, int fini){
    int medio = (ini + fini) / 2;

    if (ini > fini)
        return -1;
    
        if (x < n[ini]) return -1;
        else if(x >= n[n.size() -1]) return n[n.size() - 1];
        else if (x == n[medio]) return medio;
        else if(x > n[medio]) return findFloor(n, x, medio + 1, fini);
        else if(x < n[medio]) return findFloor(n, x, ini, medio - 1);
    
}

int main(){
    vector <int> v = {0, 0, 0, 0, 1, 1, 1};

    for (int i = 0; i < v.size(); i++)
    {
        int res1 = findCeil(v, i, 0, v.size());
        int res2 = findFloor(v, i, 0, v.size());
        cout << "Número " << i << " --> dalt es  " << res1 << " baix es " << res2 << endl;
    }
    return 0;
}
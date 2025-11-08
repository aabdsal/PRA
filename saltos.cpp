#include <iostream>
#include <vector>

using namespace std;

int saltos(vector<int>& a, int i, vector<int>& m){
    if (i >= a.size() - 1) return 0;
    if (m[i] != -1) return m[i];
    else if(a[i] == 1){
        m[i] =  1 + saltos(a, i + 1, m);
    }
    else if(a[i] == 0){
        m[i] = saltos(a,i + 1, m);
    }
    else{
        m[i] = min(saltos(a, i + a[i], m), a[i] + saltos(a, i + a[i], m));
    }
    return m[i];
}

int main(){
    vector <int> a = {2,0,0};
    vector <int> m(a.size(), -1);	
    int res = saltos(a, 1, m);
    if (!res)
    {
        cout << "No puede llegar al final" << endl;
    }else cout << "El número minimo de saltos es: " << res << endl;
}
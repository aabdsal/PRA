#include <iostream>
#include <vector>

using namespace std;

int nesimo(int x, int a){
    
    if (a == 1) return x;
    if (a % 2 == 0) return nesimo(x, a/2) * nesimo(x, a/2);
    else{
        return nesimo(x, a/2) * nesimo(x, a/2) * x;
    }
}

int main(){
    int x = 2;
    int a = 6;
    int res = nesimo(x, a);
    cout << "La potencia de " << x << " elevado a " << a << " es: " << res << endl;
}
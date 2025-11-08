#include "acortador.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

acortador::acortador(int n){
    links.resize(n);
    srand((unsigned)time(nullptr));
}
string acortador::añadir(string longUrl){
    string clave; // clave alphanumerica
    string key; // clave sin cambiar de decimal a ascii
    for (int i = 0; i < 7; i++)
    {
        int aleatorio = rand() % 2;
        int a;
        if (aleatorio) // caracter alpha
        {
            a = (rand() % 2 ? 'A':'a') + (rand() % 26);
            clave += (char)a;
            key += to_string(a);
        } 
        else{
            a = rand() % 10;
            clave += a + '0';
            key += to_string(a + '0');
        }
    }
    
    long long n = stoll(key); // convertimos a entero para sacar la n, que es la pos del vector
     
    long long c = hash(n);
    links[c].first = clave;
    links[c].second = longUrl;
    
    return clave;
}

int acortador::buscar(string clave){
    if(clave.size() != 7) return -1;
    string aux;
    for (int i = 0; i < 7; i++)
    {
        if (isalpha(clave[i])) aux[i] = (int)clave[i];
        else aux[i] = clave[i];
    }
    long long key = stoi(aux);
    int i = hash(key);
    if (links[i].second != "\0")
    {
        cout << "El link es el siguiente" << links[i].second << endl;
    } 
    else {
        return -1;
    }
    return i; // pa optimizar en borrar
}

void acortador::borrar(string clave){
    int key = buscar(clave);
    if(key >= 0) // si esta la clave bien
    {
        links[key].first = "\0";
        links[key].second = "\0";
        cout << "se ha borrado con éxito" << endl;
    } else cout << "no existe esa clave,, por tanto no hya loink guardado" << endl;
}

int acortador::getN(){
    return this->n;
}
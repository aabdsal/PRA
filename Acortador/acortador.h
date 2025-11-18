#include <iostream>
#include <vector>
#include <string>
using namespace std;

class acortador
{
private:
    int n;
    vector <pair<string, string> > links; // clave y url
    int hash(long long n) {return n % 100;} // nos da el indice para la posicion del vector

public:

    acortador(int n);
    void portada();
    void interfaz();
    void generarClave(string &clave, string &key);
    string añadir(string url);
    int buscar(string clave);
    void borrar(string clave);
    void leerFichero(string fich);
    int linear(int &i, string &clave);
    void imprimirAlmacenadas();
    int getN();
};


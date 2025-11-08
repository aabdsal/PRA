#include <iostream>
#include <vector>
#include <string>
using namespace std;

class acortador
{
private:
    int n;
    vector <pair<string, string> > links; // clave y url
    int hash(long long n) {return n % 100;}

public:
    acortador(int n);
    string añadir(string url);
    int buscar(string clave);
    void borrar(string clave);
    void leerFichero(string fich);
    int getN();
};


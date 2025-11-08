#include "acortador.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

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
        int aleatorio = rand() % 2, a;
        if (aleatorio) // caracter alpha
        {
            a = (rand() % 2 ? 'A':'a') + (rand() % 26);
            clave += (char)a;
            key += to_string(a);
        } 
        else{ // caracter númerico
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
    if(clave.size() != 7) {
        cout << "El tamaño de la clave: " << clave << "es " << clave.size() << endl;
        return -1;
    }
    string aux;

    for (int i = 0; i < 7; i++)
    {
        char c = static_cast<char>(clave[i]);
        if (isalpha(clave[i])) aux += to_string(static_cast<int>(c));
        else aux += clave[i];
    }

    long long key = stoll(aux);
    int i = hash(key);

    if (links[i].second != "\0") cout << "El link con clave " << clave << " es el siguiente: " << links[i].second << endl << endl;
    else return -1;
    
    return i; // pa optimizar en borrar
}

void acortador::borrar(string clave){
    int key = buscar(clave);
    if(key) // si esta la clave bien
    {
        links[key].first = "\0";
        links[key].second = "\0";
        cout << "Se ha borrado con éxito" << endl;
    } else cout << "No existe esa clave,, por tanto no hay link guardado" << endl;
}

void acortador::leerFichero(string fich){
    
    ifstream fichero(fich);
    if (!fichero.is_open()) throw runtime_error("No se ha podido abrir el archivo");
    
    string l1;
    ofstream salida("acortados.txt");
    while(getline(fichero,l1)){
        string c1 = añadir(l1);
        salida << "Link recortado: https//ali.ly//" << c1 << endl; // guardamos los links en un nuevo fichero
        cout << "Link recortado: https//ali.ly//" << c1 << endl; 
    }
    cout << endl;
    fichero.close();
    
    ifstream check("acortados.txt");
    string l2;
    while(getline(check,l2)){
        l2 = l2.substr(31);
        int i = buscar(l2);
        if (i < 0) throw runtime_error("Clave Inválida:" + l2);
    }
    salida.close();
    // me falta probar lo de borrar
}

int acortador::getN(){
    return this->n;
}
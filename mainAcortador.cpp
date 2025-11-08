#include "acortador.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(){
    ifstream fichero("urls.txt");
    if (!fichero.is_open())
    {
        throw runtime_error("No se ha podido abrir el archivo");
    }

    acortador a1(100); // inicializamos el vector a 100 posiciones
    
    string l1;
    ofstream salida("acortados.txt");
    while(getline(fichero,l1)){
        string c1 = a1.añadir(l1);
        salida << "Link recortado: https//ali.ly//" << c1 << endl; // guardamos los links en un nuevo fichero
        cout << "Link recortado: https//ali.ly//" << c1 << endl; 
    }
    
    ifstream check("acortados.txt");
    string l2;
    while(getline(check,l2)){
        string aux;
        check >> aux;

        int i = a1.buscar(l2);
        if (i < 0) cout << "No hay ningun link o la clave es inválida\n";
        // me falta probar lo de buscar i lo de borrar
    }
    
    fichero.close(); // añadido 100 urls
    salida.close();
}
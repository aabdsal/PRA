#include "acortador.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(){
    acortador a1(100); // inicializamos el vector a 100 posiciones
    string fich; 
    cout << "Dime el nombre del fichero con los links: "; cin >> fich;
    a1.leerFichero(fich); // fichero con links a acortar
    return 0;
}
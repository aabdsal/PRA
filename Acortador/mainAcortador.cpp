#include "acortador.h"
#include <chrono>
using namespace std;
/*
Tarea
1. implementa un acortador de URL en C++ con tabla hash
2. introduce 100 URL en la tabla
3. estudia el efecto de las dos funciones hash para cadenas: Opcion sencilla y la opcion de usar un código posicional usando un polinomio
4. estudia el efecto de distintos tamaños de m
5. estudia el efecto de las tres funciones de direccionamiento
*/
int main(){
    acortador a1(100);
    try
    {
        a1.portada();
        a1.interfaz();
    }
    catch(runtime_error& e)
    {
        cerr << e.what() << '\n';
    }
    // me falta la part opcional de rebollin

    return 0;
    
}
/*
    Me queda la part de estudi: 
    La entrega consiste en el código fuente desarrollado y una memoria (para la parte opcional) 
    en la que se analice el rendimiento de la tabla hash. Para estudiar el efecto de cada decisión, 
    haz varias repeticiones con el mismo escenario y calcula valores medios y desviaciones. 
    Por ejemplo, para el tamaño de m, genera un rango de valores (ej: de 110 a 200), incluyendo valores primos. 
    Para cada valor, repite la generación de URL (mínimo 10 veces)  y calcula el número de colisiones, 
    dispersión de las entradas por la tabla o cualquier otro valor que consideres.
*/
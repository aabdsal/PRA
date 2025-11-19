#include "acortador.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <chrono>

using namespace std;

acortador::acortador(int n){
    this->n = 0;
    links.resize(n);
    srand((unsigned)time(nullptr));
}

void acortador::portada(){

    cout << endl << "************************************************************************************************" << endl;
    cout << "************************************************************************************************" << endl;
    cout << "*************************** A C O R T A D O R  U R L ' S  d e  A L I ***************************" << endl;
    cout << "************************************************************************************************" << endl;
    cout << "************************************************************************************************" << endl << endl;

}

void acortador::interfaz(){
    
    acortador a1(100); // inicializamos el vector a 100 posiciones
    cout << endl << "Tiene 7 opciones a elegir:" << endl << endl;
    cout << "1: Añadir Url                  2: Añadir Url's mediante fichero" << endl;
    cout << "3: Buscar Url mediante clave   4: Borrar Url" << endl;
    cout << "5: Número de Url's lmacenadas  6: Imprimir las urls Almacenadas" << endl;
    cout << "7: Salir del programa" << endl << endl;

    int n, i;
    cout << "Elige: ";
    cin >> n; 
    cin.ignore();

    string fich;     

    switch (n)
    {
    case 1:
        cout << "Dime la Url a añadir: "; cin >> fich;
        añadir(fich);
        break;
    case 2:
        cout << "Dime el nombre del fichero con los links: "; cin >> fich;
        leerFichero(fich);
        break;
    case 3:
        cout << "Dime la clave a buscar: "; cin >> fich;
        i = buscar(fich);
        break;
    case 4:
        cout << "Dime la clave con el Url a borrar: "; cin >> fich;
        borrar(fich);
        break;
    case 5:
        cout << "Número de Url's almacenadas: " << getN() << endl;
        break;
    case 6:
        imprimirAlmacenadas();
        break;
    case 7:
        cout << "Saliendo..." << endl;
        return;
    default:
        cout << "Nº inválido" << endl;
        interfaz();
        break;
    }
    interfaz();
}
void acortador::generarClave(string &clave, string &key){
    clave = "\0";
    key = "\0";

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
}
string acortador::añadir(string longUrl){

    string clave; // clave alphanumerica
    string key; // clave sin cambiar de decimal a ascii
    generarClave(clave, key);
    long long n = stoll(key); // convertimos a entero para sacar la n, que es la pos del vector
     
    int i = hash(n);
    if (!links.empty()) // si no esta buit
    {
        linear(i, clave); // buscar la seguent posició buida
    }

    links[i].first = clave;
    links[i].second = longUrl;
    this->n++;

    return clave;
}

int acortador::buscar(string clave){
    cout << endl << "Clave a buscar: " << clave << endl;
    if(clave.size() != 7) throw runtime_error("Tamaño de clave inválido\n");
    string key;
    
    for (int i = 0; i < 7; i++)
    {
        char c = static_cast<char>(clave[i]);
        if (isalpha(clave[i])) key += to_string(static_cast<int>(c));
        else key += clave[i];
    }

    long long n = stoll(key);
    int i = hash(n);
    if (links[i].first != clave){
        cout << "Esta ocupada esa posición, posiblemente le hayamos hecho un hash lineal" << endl;
        if(linear(i, clave) < 0){
            cout << "La clave no se encuentra en la Base de Datos" << endl;
            return -1;
        }
    }
    cout << "El link con clave " << links[i].first << " es: " << links[i].second << endl;
    return i; // pa optimizar en borrar
}

int acortador::linear(int &i, string &clave){
    int prev = i;
    while (!links[i].second.empty()) // mientras no este vacio, soc moet
    {
        i = (i + 1) % links.size(); // movimiento circular, aixina fem una busqueda d (i a n) i de (0 a i)
        if (clave == links[i].first) // pa la funcia de buscar
        {
            return i;
        }
        
        if (i == prev){
            return -1;
        }
    }
    
    return i;
}
void acortador::borrar(string clave){
    int key = buscar(clave);
    if(key > -1) // si esta la clave bien
    {
        links[key].first = "\0";
        links[key].second = "\0";
        this->n--;
        cout << "Se ha borrado con éxito✅" << endl;
    } else cout << "No existe esa clave, por tanto no hay un link guardado" << endl;
}

void acortador::leerFichero(string fich){
    auto start = chrono::high_resolution_clock::now();
    ifstream fichero(fich);
    if (!fichero.is_open()) throw runtime_error("No se ha podido abrir el archivo");
    
    string l1;
    ofstream salida("acortados.txt");
    while(getline(fichero,l1)){
        string c1 = añadir(l1);
        salida << "https//ali.ly//" << c1 << endl; // guardamos los links en un nuevo fichero
    }
    fichero.close();
    cout << "Url's añadidas con éxito ✅" << endl;
    auto end = chrono::high_resolution_clock::now();
    // me falta la part opcional de rebollin
    auto lapse = chrono::duration_cast<chrono::seconds>(end - start);

    cout << "Tiempo requerido para añadir las Url's: " << lapse.count() << endl;
}

void acortador::imprimirAlmacenadas(){
    for (int i = 0; i < links.size(); i++)
    {
        if (!links[i].second.empty()) // si no esta vacio
        {
            cout << links[i].second << endl;
        }
    }
}
int acortador::getN(){
    return this->n;
} 
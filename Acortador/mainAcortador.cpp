#include "acortador.h"

using namespace std;

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
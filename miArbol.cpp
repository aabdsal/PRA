#include <iostream>
using namespace std;

struct miArbol 
{
    int data;
    miArbol *esquerra;
    miArbol *dreta;

    miArbol(int data){
        this->data = data;
        esquerra = nullptr;
        dreta = nullptr;
    }
};


void preOrden(miArbol *info){
    if (info == nullptr) {return;}
    
    cout << info->data << " ";
    preOrden(info->esquerra);
    preOrden(info->dreta);
    
}
void inOrden(miArbol *info){
    if (info == nullptr) {return;}
    
    inOrden(info->esquerra);
    cout << info->data << " ";
    inOrden(info->dreta);
    
}
void posOrden(miArbol *info){
    if (info == nullptr) {return;}
    
    posOrden(info->esquerra);
    posOrden(info->dreta);
    cout << info->data << " ";
    
}
void insert(miArbol *&ini, int data){ 

    if (ini == nullptr) {
        ini = new miArbol(data);
        return;
    }
    
    if(data == ini->data){
        cout << "Ya esta el nodo " << ini->data <<" nodo guardado\n";
        return;
    }

    if (data > ini->data){insert(ini->dreta, data);} // si es más grande a la derecha, sino a la izquierda
    else {insert(ini->esquerra, data);}
    
}

void borrar(miArbol *&ini, int data){ 

    if (ini == nullptr) {
        cout << "Nodo no encontrado";
        return;
    }
    
    if(data == ini->data){
        delete ini;
        ini = nullptr;
        cout << "Nodo eliminado\n";
        return;
    }

    if (data > ini->data){borrar(ini->dreta, data);} // si es más grande a la derecha, sino a la izquierda
    else {borrar(ini->esquerra, data);}
    
}
int main(void){
    miArbol *arbre = nullptr;

    insert(arbre, 2);
    insert(arbre, 3);
    insert(arbre, 4);
    insert(arbre, 5);
    insert(arbre, 6);
    insert(arbre, 5);


    cout << "Recorrido preOrden: ";
    preOrden(arbre);
    cout << endl;
    
    borrar(arbre,6);
        
    cout << "Recorrido preOrden despres de eliminar el 5: ";
    preOrden(arbre);
    cout << endl;

    /*
    cout << "Recorrido inOrden: ";
    inOrden(arbre);
    cout << endl;

    cout << "Recorrido posOrden: ";
    posOrden(arbre);
    cout << endl;
    */
    return 0;
}
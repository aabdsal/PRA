#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
	 	Node<T>* first;
        int n;
	// tenim data y next
    public:

   	ListLinked(){
		first = nullptr;
		n = 0;
	}
	~ListLinked(){
		Node<T>* aux = first;
		Node<T>* nextNode;
		
		while(aux != nullptr){ 
			nextNode = aux->next;
			delete aux;
			aux = nextNode;
		}
	}
	T operator[](int pos){
		return get(pos); // fan lo mateix
	}
	friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
		Node<T>* aux = list.first;
	    out << "List => [";
	    if (aux != nullptr) {
		out << endl << "    "<< aux->data << endl;
		aux = aux->next; // apuntar al seguent nodo
	    }
	    while (aux != nullptr) {
	        out << "   " << aux->data << endl;
		aux = aux->next; // apuntar al seguent nodo
	    }
	
	    out << "]";
	    return out; // variable que te lo q anem a imprimir
	}
	void insert(int pos, T e) override{
		if(pos < 0 || pos > n) throw out_of_range("Posición fuera del rango de la array");
		if(pos == 0){ // si no hay ningun nodo
			Node<T>* aux = new Node<T>(e,first); 
			first = aux;
			n++;
		}
		else{ // Caso general
			Node<T>* prev = nullptr;
			Node<T>* aux = first;
			int i = 0;
			while(aux != nullptr && i < pos){
				prev = aux; // apuntar al nodo en el que estamos
				aux = aux -> next; // avanzar al siguiente nodo
				i++; // contador
			}
			if(i == pos){
				prev->next = new Node<T>(e,aux); // insertamos nuevo nodo
				n++;
			}	
		}
	}
	void append(T e) override{
		insert(n,e); // alfinal
	}
	void prepend(T e) override {
		insert(0,e); // alprincipio
	}
	T get(int pos) override{
		if(pos < 0 || pos >= n) throw out_of_range("Posición fuera del rango de la array");
		Node<T>* aux = first;
		for(int i= 0; i < pos; i++) aux = aux->next; // busqueda lineal
		return aux->data;
    }
    int search(T e) override {
        Node<T>* aux = first;
		
		int i = 0;
		while(aux != nullptr && aux-> data != e){
			aux = aux-> next;
			i++;
		}
		if(aux != nullptr) return i;
		else return -1;
    }

	bool empty() override{ // ez
        if (n == 0) return true;
        else return false;
    }
    int size() override{ // ez
        return n;
    }
	T remove(int pos) override{
		if(pos < 0 || pos > n) throw out_of_range("No esta en el array");
		Node<T>* prev = nullptr;
    	Node<T>* aux = first;
		int i = 0;
    	while (aux != nullptr && i < pos) {
        	prev = aux; // apunta al nodo en el que estem
        	aux = aux->next; // avancem hasta el nodo que volem eliminar
			i++; // contador
   		}
		T res = 0;
    	if (aux != nullptr) { // si aux apunta al nodo
        	if (aux == first) first = aux->next; // si es el primer cas
			else prev->next = aux->next; // bypass per a que el de antes apunte al de després
		
			res = aux->data; // guardem valor
        	delete aux; // eliminem de memoria
        	n--;
    	}
		return res;
	}
	void duplicate_list() override{
	     Node<T>* prev = nullptr;
             Node<T>* aux = first;
		int i = 0;
      	               				
            while(aux != nullptr && i < n){
                prev = aux; // apuntar al nodo en el que estamos
                aux = aux -> next; // avanzar al siguiente nodo y usamos su data
		i++;
          }
		Node<T>* info = first;
		
		while(i < n * 2 ){
			Node<T>* newNode  = new Node<T>(info->data,aux); // insertamos nuevo nodo
			prev->next = newNode;
			prev = newNode; // soc un desmayat
			info = info->next;
			i++;
		}
		n = i; 
	}
};

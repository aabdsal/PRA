#include <ostream>
#include "List.h"

using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	void resize(int size)
	{
		T* pepe = new T[size];
		for(int i = 0; i < n; i++) pepe[i] = arr[i];
		
		delete[] arr; // eliminamos contenido de arr
		arr = pepe; // le asignamos a arr el contenido y el nuevo tamaño
		max = size; // contador actualizado
	}
	static const int MINSIZE = 2; //inicializamos y nadie puede modificarlo
	
    public:
        // miembros públicos, incluidos los heredados de List<T>
	void insert(int pos, T e) override{
		if(pos < 0 || pos > n) throw out_of_range("Posición fuera del rango de la array");
		if(pos== 0) arr[0] = e;	// primer caso
		else { // caso general
			for(int i = n - 1; i >= pos; i--) arr[i + 1] = arr[i];
			arr[pos] = e;
		}
		n++;
		resize(n); // aumentamos tamaño
	}    	
	void append(T e) override
	{
		insert(n,e); // añadimos al final
	}
	void prepend(T e) override 
	{
		insert(0,e); // añadimos al principio
	}
	T get(int pos) override
	{
		if(pos < 0 || pos >= n) throw out_of_range("Posición fuera del rango de la array");
		return arr[pos]; // simple y llano
	}
	int search(T e) override
	{
		for(int i = 0; i < n; i++) if(arr[i] == e) return i; // busqueda lineal
		return -1;
	}
	
	bool empty() override 
	{
		if (n == 0) return true; // comprobar tamaño del vector con el contador
		else return false;
	}
	int size() override{
		return n; // tamaño del vector usando el contador
	}
	ListArray(){ // constructor con 2 espacios vacios
		arr = new T[MINSIZE];
		n = 0;
		max = MINSIZE;
	}
	~ListArray(){
		delete[] arr; // eliminamos memoria
	}
	T operator[](int pos){ // igual que el get
		if(pos < 0 || pos > n) throw out_of_range("Posición fuera del rango de la array");
        return arr[pos];
	}
	friend ostream& operator<<(ostream &out, const ListArray<T> &list){
		out << "List => [" << endl;
		for(int i = 0; i < list.n; i ++) out << "   "<< list.arr[i] << endl;
		out << "]";
		return out;
	}
	T remove(int pos) override
	{
		if(pos < 0 || pos >= n) throw out_of_range("Posición fuera del rango de la array");
		T res = arr[pos];
		for(int i = pos; i < n - 1; i++) arr[i] = arr[i + 1]; // empezamos desde pos
		n--;
		resize(n);
		return res;
	}
};

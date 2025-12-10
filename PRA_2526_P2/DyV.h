#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template <typename T> 
int BusquedaBinaria(T x, vector <T>& v, int ini, int fin){

	int medio = (ini + fin) / 2;

	if(ini > fin){ 
		cout << "El valor no se encuentra el array\n";
		return -1;
	}
	else if(v[medio] == x) return medio;
	else if(v[medio] > x) return BusquedaBinaria(x, v, ini,  medio -1);
	else return BusquedaBinaria(x, v, medio + 1, fin);
}

template <typename T>
int Partition(vector <T> &v, int ini, int fin){

	T x = v[fin];
	int i = ini;
	for (int j = ini; j < fin - 1; j++){
		if(v[j] <= x){
			swap(v[i], v[j]);
			i += 1;
		}
    }
	swap(v[i],v[fin]);
	return i;
}

template <typename T>
void QuickSort(vector <T> &v, int ini, int fin){

        if(ini < fin){
            int pivot = Partition(v, ini, fin);
            QuickSort(v, ini, pivot- 1);
            QuickSort(v, pivot + 1, fin);
        }
}

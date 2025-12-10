#include <iostream>
#include <set>
#include <fstream>

using namespace std;

class Nodo{
private:
  int data;
  Nodo* next;
public:
  Nodo(int data, Nodo* next = nullptr){
  this->data = data;
  this->next = next;
  }
};

struct camelCards
{
   string cartas;
   int bet;
   Nodo* izquierdo;
   Nodo* derecho;
};

vector<char> orden = {'A','K', 'Q', 'J', 'T', '9', '8', '7','6','5','4','3','2'};
int calcular_rango(string c1, string c2, vector<char> orden){
  set <char> t1; 
  for (int i = 0; i < c1.size(); i++)
  {
    t1.insert(c1[i]);
  }
  set <char> t2; 
  for (int i = 0; i < c1.size(); i++)
  {
    t2.insert(c1[i]);
  }
  if (t1.size() < t2.size())
  {
    /* code */
  }
      
}7890'
void Inorden(camelCards &x, vector<int>& resultado){
  if (x.izquierdo != nullptr){
      Inorden(x.izquierdo, resultado);   // 1. Recorre el subárbol izquierdo
      resultado.push_back(x.bet);      // 2. Guarda el valor del nodo
      Inorden(x.derecho, resultado);     // 3. Recorre el subárbol derecho
  }
};


int main(){
    ifstream fichero("imput.txt");
    if (!fichero.is_open()) throw runtime_error("No se encuentra");
    camelCards x;
    string c1,c2;
    int res = calcular_rango(c1,c2,orden);
    vector<int> resultado;
    Inorden(x,resultado);
    return 0;
    
}


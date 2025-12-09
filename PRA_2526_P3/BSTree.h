#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

using namespace std;

template <typename T> 
class BSTree {
    private:
        //miembros privados
	int nelem;
	BSNode<T> *root;
	
	BSNode<T>* search(BSNode<T>* n, T e) const{
		if(n->elem == e) {return n;}
		else if(n->elem > e) { return search(n->left, e);}
		else if(n->elem < e) { return search(n->right, e);}
		else {throw runtime_error("Elemento no encontrado");}
	}
	
	BSNode<T>* insert(BSNode<T>* n, T e){
		if(n == nullptr){
			return new BSNode<T>(e, nullptr, nullptr);	
		}
		else if(n->elem == e) { throw runtime_error("El elemento e ya existe");}
                else if(n->elem > e) { return insert(n->left, e);}
                else if(n->elem < e) { return insert(n->right, e);}
	}
	
	void print_inorder(std::ostream &out, BSNode<T>* n) const{
		if(n == nullptr){
			return;
		}
		print_inorder(out, n->left);
		out << n->elem << endl;
		print_inorder(out, n->right);
	}
	
	BSNode<T>* remove(BSNode<T>* n, T e){
                if(n->elem > e) { return insert(n->left, e);}
                else if(n->elem < e) { return insert(n->right, e);}
		else if(n->elem == e) {
			if(n->left == nullptr && n->right == nullptr){ // 0 hijos
				delete[] n;
				n == nullptr;
			}
			
			if(n->left == nullptr){ // 1 hijo a la derecha
				BSNode<T>* aux = n->right;
				delete [] n;
				n = aux;
			}
			else if(n ->right == nullptr){ // 1 hijo a la izquierda
				BSNode<T>* aux = n->left;
				delete[] n;
				n = aux;
			}
			else if(n->left != nullptr && n->right != nullptr){ // 2 hijos
				n->elem = max(n->left);
				n->left = remove_max(n->left);
			}
		}
		else if (n == nullptr){
			throw runtime_error("Elemento no encontrado");
		}
	
	}

	T max(BSNode<T>* n) const{
		if(n == nullptr) {
			throw runtime_error("Elemento no encontrado");
		}
		else if(n->right != nullptr){
			return max(n->right);
		}
		else{
			return n->elem;
		}
	}
	
	
	BSNode<T>* remove_max(BSNode<T>* n){
		if (n->right == nullptr){
        		return n->left;
		}
    		else{
        		n->right = remove_max(n->right);
       		 	return n;
		}
	}
	
	void delete_cascade(BSNode<T>* n){	
		delete_cascade(n->left);
		delete_cascade(n->right);
		delete[] n;
	}

    public:
        // miembros públicos
   	BSTree(){
		this->root = nullptr;
	}
	int size() const{
		return nelem;
	}
	T search(T e) const{
		return search(root, e);
}
	T operator[](T e) const{
		return search(e);
	}
	void insert(T e){
		return insert(root, e);
	}
	friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
		bst.print_inorder(out, bst);
		return out;
	}
	void remove(T e){
		return remove(root, e);
	}
	~BSTree(){
		delete_cascade(root);
	}
	
};

#endif

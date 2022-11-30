#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

template<class T>
class Nodo{
  public:
    T dato;
    Nodo<T>* sig;
    Nodo(T dato){
      this->dato = dato;
    }
};

template<class T>
class Lista{
  private:
    Nodo<T>* t_head;
    int size;
  public:
    Lista(){
      t_head = nullptr;
      size = 0;
    }
    ~Lista(){
      delete t_head;
    }
    
	 void Print()
	 {
		 Nodo<T> * tmp = t_head;
		 while(tmp!=0)
		 {
			 cout<<tmp->dato<<endl;
			 tmp = tmp->sig;
		 }
	 }

    void pushFront(T dato){
      Nodo<T>* nuevoNodo = new Nodo<T>(dato);
      if(t_head == nullptr){
        t_head = nuevoNodo;
        size++;
      }
      else{
        Nodo<T>* aux = t_head;
        t_head = nuevoNodo;
        nuevoNodo->sig = aux;
        size++;
      }
    }
    
    void pushBack(T dato){
      Nodo<T>* nuevoNodo = new Nodo<T>(dato);
      if(t_head == nullptr){
        t_head = nuevoNodo;
        size++;
      }
      else{
        Nodo<T>* aux = t_head;
        Nodo<T>* aux2;
        while (aux != nullptr) {
          aux2 = aux;
          aux = aux->sig;
        }
        aux2->sig = nuevoNodo;
        nuevoNodo->sig = aux;
        size++;
      }
    }

    void popFront(){
      Nodo<T>* aux = t_head;
      t_head = t_head->sig;
      size--;
      delete aux;
    }
    void popBack(){
      Nodo<T>* aux = t_head;
      if(aux == nullptr){
        cout<<"No hay nada que eliminar.";
      }
      else{
        Nodo<T>* aux2;
        if(aux->sig == nullptr){
          t_head = nullptr;
          size--;
          delete aux;
        }
        else{
          while (aux->sig != nullptr) {
            aux2 = aux;
            aux = aux->sig;
          }
          aux2->sig = nullptr;
          size--;
          delete aux;
        }
      }
    }
    
    string data(T dato){
      string a = to_string(dato)+" ";

      a += "[label=\"{ <data> ";
      a += to_string(dato);
      a+= "| <ref>  }\"];\n";

      return a;
    }

    void print(){
      string nombreArchivo = "grafico.dot";
      ofstream archivo;
      archivo.open(nombreArchivo.c_str(), fstream::out);
      archivo << "digraph foo {\n\trankdir=LR;\n\tnode [shape=record];\n\thead->";
      Nodo<T>* aux = t_head;
      if(aux == nullptr){
        archivo << "null;}";
        archivo.close();
        system("dot -Tpdf grafico.dot -o archivo.pdf");
        system("zathura archivo.pdf &");
        return;
      }
      
      archivo << to_string(aux->dato)+";\n";

      while(aux != nullptr){
        archivo << "\t"+data(aux->dato);
        archivo << "\t"+to_string(aux->dato) + ":ref:c -> ";
        if(aux->sig != nullptr){
          archivo <<to_string(aux->sig->dato) + ":data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];\n"; 
        }
        else{
          archivo << "null [shape=box, arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];\n}";
        }
        aux = aux->sig;
      }

      archivo.close();

      system("dot -Tpdf grafico.dot -o archivo.pdf");
      //system("dot -Tjpg grafico.dot -o archivo.jpg");
      //system("feh archivo.jpg &");
      system("zathura archivo.pdf &");
    }

    friend ostream &operator<<(ostream &os, const Lista &a){
      Nodo<T>* aux = a.t_head;
      if(aux == nullptr){
        os<<"Lista vacia."<<endl;
        return os;
      }
      while(aux != nullptr){
        os<<aux->dato<<" - ";
        aux = aux->sig;
      }
      os<<endl;
      return os;
    }


};

/*
int main(){
  Lista<int>lista;
  cout<<lista;
  lista.pushFront(1);
  lista.print();
  cout<<lista;
  lista.pushBack(2);

  lista.print();
  cout<<lista;
  lista.pushBack(3);
 
  lista.print();

  cout<<lista;
  lista.popBack();
  cout<<lista;
  lista.popBack();
  cout<<lista;
  lista.popBack();
  cout<<lista;

  lista.data(1);
  return 0;
}*/

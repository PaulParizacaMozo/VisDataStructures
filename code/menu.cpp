#include "lista.cpp"
#include "cola.cpp"
#include "pila.cpp"
#include "abinario.cpp"
#include "avl.cpp"
#include "rb.cpp"
#include "hash.cpp"
#include "sparse.cpp"
#include <iostream>
using namespace std;

void menuPrincipal(){
  cout<<"\n******GRAFICADOR DE ESTRUCTURA DE DATOS******"<<endl;
  cout<<"OPCIONES"<<endl;
  cout<<"1.- Pilas\n2.- Colas\n3.- Lista Enlazada Simple\n4.- Lista Enlazada Doble\n5.- Arbol Binario\n6.- AVL\n7.- Arbol RedBlack\n8.- Tablas Hash\n9.- Matriz Esparsa\n0.- SALIR"<<endl;
  cout<<"Ingrese una opcion -> ";
}

void menuPila(){
  Pila<int>pila; 
  bool salir = false;
  int opt;
  int aux;
  while (salir == false){
    cout<<"\n***MENU DE PILA"<<endl;
    cout<<" 1.- Push\n 2.- Pop\n 3.- Mostrar grafico\n 0.- SALIR"<<endl;
    cout<<" Ingrese una opcion -> ";
    cin>>opt;
    switch (opt) {
    case 1:
      cout<<"  Ingrese el dato a insertar -> ";cin>>aux;
      pila.push(aux);
      pila.dibujar();      
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 2:
      pila.pop(); 
      pila.dibujar();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 3:
      pila.dibujar();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 0:
      salir = true;
      break;
    }
  }
}

void menuCola(){
  Cola<int>cola; 
  bool salir = false;
  int opt;
  int aux;
  while (salir == false){
    cout<<"\n***MENU DE COLA"<<endl;
    cout<<" 1.- Push\n 2.- Pop\n 3.- Mostrar grafico\n 0.- SALIR"<<endl;
    cout<<" Ingrese una opcion -> ";
    cin>>opt;
    switch (opt) {
    case 1:
      cout<<"  Ingrese el dato a insertar -> ";cin>>aux;
      cola.Push(aux);
      cola.dibujar();      
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 2:
      cola.Pop(); 
      cola.dibujar();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 3:
      cola.dibujar();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 0:
      salir = true;
      break;
    }
  }
}
void menuLista(){
  Lista<int>lista; 
  bool salir = false;
  int opt;
  int aux;
  while (salir == false){
    cout<<"\n***MENU DE LISTA ENLAZADA SIMPLE"<<endl;
    cout<<" 1.- Push Front\n 2.- PushBack\n 3.- PopFront\n 4.- PopBack\n 5.- Mostrar Grafico\n 0.- SALIR"<<endl;
    cout<<" Ingrese una opcion -> ";
    cin>>opt;
    switch (opt) {
    case 1:
      cout<<"  Ingrese el dato a insertar -> ";cin>>aux;
      lista.pushFront(aux);
      lista.print();      
      cin.ignore(); //limpiar buffer
      cin.get();    //system("pause") equivalente
      system("killall zathura");
      break;
    case 2:
      cout<<"  Ingrese el dato a insertar -> ";cin>>aux;
      lista.pushBack(aux);
      lista.print();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 3:
      lista.popFront();
      lista.print();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 4:
      lista.popBack();
      lista.print();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 5:
      lista.print();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 0:
      salir = true;
      break;
    }
  }
}

void menuArbolBinario(){
  Tree<int>ab; 
  bool salir = false;
  int opt;
  int aux;
  while (salir == false){
    cout<<"\n***MENU DE ARBOL BINARIO"<<endl;
    cout<<" 1.- Insertar\n 2.- Find\n 3.- Eliminar\n 4.- Mostrar grafico\n 0.- SALIR"<<endl;
    cout<<" Ingrese una opcion -> ";
    cin>>opt;
    switch (opt) {
    case 1:
      cout<<"  Ingrese el dato a insertar -> ";cin>>aux;
      ab<<aux;
      ab.Draw();      
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 2:
      cout<<"  Ingrese el dato a buscar -> ";cin>>aux;
      ab.Find_Draw(aux);
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 3:
      cout<<"  Ingrese el dato a eliminar -> ";cin>>aux;
      ab.Delete(aux); 
      ab.Draw();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 4:
      ab.Draw();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 0:
      salir = true;
      break;
    }
  }
}

void menuAVL(){
  Avl<int>avlTree; 
  bool salir = false;
  int opt;
  int aux;
  while (salir == false){
    cout<<"\n***MENU DE ARBOL BINARIO EQUILIBRADO***"<<endl;
    cout<<" 1.- Insertar\n 2.- Find\n 3.- Mostrar grafico\n 0.- SALIR"<<endl;
    cout<<" Ingrese una opcion -> ";
    cin>>opt;
    switch (opt) {
    case 1:
      cout<<"  Ingrese el dato a insertar -> ";cin>>aux;
      avlTree<<aux;
      avlTree.Draw();      
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 2:
      cout<<"  Ingrese el dato a buscar -> ";cin>>aux;
      //avlTree.Delete(aux); 
      //avlTree.Draw();
      avlTree.Find_Draw_AVL(aux);
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 3:
      avlTree.Draw();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 0:
      salir = true;
      break;
    }
  }
}

void menuRB(){
  RedBlackTree<int>rb; 
  bool salir = false;
  int opt;
  int aux;
  while (salir == false){
    cout<<"\n***MENU DE ARBOL BINARIO EQUILIBRADO***"<<endl;
    cout<<" 1.- Insertar\n 2.- Find\n 3.- Mostrar grafico\n 0.- SALIR"<<endl;
    cout<<" Ingrese una opcion -> ";
    cin>>opt;
    switch (opt) {
    case 1:
      cout<<"  Ingrese el dato a insertar -> ";cin>>aux;
      rb<<aux;
      rb.Draw();      
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 2:
      cout<<"  Ingrese el dato a buscar -> ";cin>>aux;
      //avlTree.Delete(aux); 
      //rb.Draw();
      rb.Find_Draw_RB(aux);
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 3:
      rb.Draw();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 0:
      salir = true;
      break;
    }
  }
}

void menuHash(){
  Hash<int, FD2> H;
  bool salir = false;
  int opt, aux;
  std::string key;
  while (salir == false){
    cout<<"\n*** MENU DE TABLA DE HASH ***"<<endl;
    cout<<" 1.- Insertar\n 2.- Mostrar grafico\n 0.- SALIR"<<endl;
    cout<<" Ingrese una opcion -> ";
    cin>>opt;
    switch (opt) {
    case 1:
      cout<<"  Ingrese el dato a insertar (int) -> ";cin>>aux;
      cout<<"  Ingrese key a usar en la funcion de dispersion (palabra) -> "; cin>>key;
      H.Insert(key,aux);
      cin.ignore();   
      H.Draw(); 
      cin.ignore();   
      cin.get(); 
      system("killall zathura");
      break;
    case 2:
      cin.ignore();   
      H.Draw();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 0:
      salir = true;
      break;
    }
  }
}


void menuSparse(){
  //int fil;
  //cout<<" Ingrese el numero de filas -> ";cin>>fil;
  //cout<<" Ingrese el numero de columnas -> ";cin>>col;
  Matrix<int,5,5>spar; 
  bool salir = false;
  int opt;
  int aux;
  int fil,col;
  while (salir == false){
    cout<<"\n***MENU DE ARBOL BINARIO EQUILIBRADO***"<<endl;
    cout<<" 1.- Insertar\n 2.- Eliminar\n 3.- Mostrar grafico\n 0.- SALIR"<<endl;
    cout<<" Ingrese una opcion -> ";
    cin>>opt;
    switch (opt) {
    case 1:
      cout<<"  Ingrese el dato a insertar -> ";cin>>aux;
      cout<<"  Ingrese la fila -> ";cin>>fil;
      cout<<"  Ingrese la columna -> ";cin>>col;
      spar.Insert(aux,fil,col);
      spar.dibujar();      
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 2:
      cout<<"  Ingrese el dato a eliminar -> ";cin>>aux;
      cout<<"  Ingrese la fila -> ";cin>>fil;
      cout<<"  Ingrese la columna -> ";cin>>col;
      spar.dibujar();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 3:
      spar.dibujar();
      cin.ignore();
      cin.get();
      system("killall zathura");
      break;
    case 0:
      salir = true;
      break;
    }
  }
}


int main(){
  bool mPrin = false;
  int opt;
  while (mPrin == false){
    menuPrincipal();
    cin>>opt;
    switch (opt) {
      case 1:
        menuPila();
        break;
      case 2:
        menuCola();
        break;
      case 3:
        menuLista();
        break;
      case 5:
        menuArbolBinario();
        break;
      case 6:
        menuAVL();
        break;
      case 7:
        menuRB();
        break;
      case 8:
        menuHash();
        break;
      case 9:
        menuSparse();
        break;
      case 0:
        mPrin = true;
        break;
    }
  }
  cout<<"Saliendo del programa ..."<<endl;
  return 0;
}

#include <string> //LIFO
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class NodoP {
  public:
    T m_Dato;
    NodoP<T> * m_pAnt;

    NodoP(T d) {
      m_Dato = d;
      m_pAnt = nullptr;
    }
};

template <class T>
class Pila {
  private:
    NodoP<T> * m_pTope; // ultimo insertado
  public:
    Pila() {
      m_pTope = 0;
    }
    bool IsEmpty() {
      return m_pTope==0;         
    }

    void push(T d) {
      NodoP<T> * pNuevo = new NodoP<T>(d); 
      if(!m_pTope)  // si esta vacio inserta 1er NodoP
        m_pTope =  pNuevo;
      else {
        pNuevo->m_pAnt = m_pTope; 
        m_pTope = pNuevo; // ahora tope apunta al ultimo elemento de encima
      }
    }
    
    void pop() {
      if(!m_pTope) return; // si esta vacio retorna
      NodoP<T> * tmp = m_pTope; 
      m_pTope = m_pTope->m_pAnt; // tope ahora es el penultimo 
      delete tmp; // liberamos el ultimo
    }

    T Top() {
      if(!IsEmpty())  
          return (m_pTope->m_Dato);
      return 0;
    }


    void dibujar(){
      //if(!m_pTope) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoPila.dot",ios::out); limpiar<<""; limpiar.close(); // limpia archivo
      archivo.open("archivoPila.dot",ios::app); 
      if(archivo.fail()){ cout<<"No se puede abrir archivo"<<endl; exit(1); }
      archivo<<"digraph G{\n";
      archivo<<"\ttop [label=\"top\" shape=\"rect\" style=rounded];\n";
      archivo<<"\tsubgraph cluster_0 {\n";
      archivo<<"\tstyle=filled;\n\tcolor=white;\n\tnode [style=filled];\n\tnode[shape=record]\n";
      NodoP<T>* pTmp = m_pTope;
      if(!m_pTope){
        archivo<<"null[label=\"NULL\" shape=circle]";
        archivo<<"top -> null"<<"\n";
        archivo<<"\n\t}\n}"; // cerrar cluster y cerrar digraph
        archivo.close();
        system("dot -Tjpg archivoPila.dot -o archivoPila.jpg"); return;
      }
      int i = 0;
      do{
        archivo<<"\t\tnodo_"<<i<<"[label=\"<ant> a | <dato> "<<pTmp->m_Dato<<"\"]\n";
        pTmp = pTmp->m_pAnt;
        i++;
      }while(pTmp);
      i-=1;
      for(int k=0; k<i; k++){
        archivo<<"\t\tnodo_"<<k<<":ant -> nodo_"<<k+1<<":dato\n";
      }
      archivo<<"\n\t}\n}"; // cerrar cluster y cerrar digraph
      archivo.close();
      system("dot -Tjpg archivoPila.dot -o archivoPila.jpg");
    }
};

int main(){
  Pila<int> A;
  int op, dato;
  while(1){
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"[1] Push\t[2] Pop\t[3] Draw"<<endl;
    cin>>op;
    if ( op==1 ) {
      cout<<"Ingrese dato => "; cin>>dato;
      A.push(dato); A.dibujar();
    } else if( op==2 ){
      A.pop(); A.dibujar();
    } else if( op==3 ){
      A.dibujar();
    } else break;
  }
  return 0;
}
